///////////////////////////////////////////////////////////////////////////////
// Name:        fractal.cpp
// Purpose:     demo of wxConfig and related classes
// Author:      Andrew Davison
// Created:     05.04.94
// Copyright:   (c) 1994 Andrew Davison
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////


/*
Date: Tue, 5 Apr 1994 12:01:18 +1000
From: Andrew Davison <andrewd@au.com.sfe>
To: wxwin-users@ed.aiai
Subject: Fractal mountains

Hi,

This is a quick port of a fractal mountain generator originally
done for MS-Windows. On a Sun the colours look a little washed
out and there is not as much snow or high mountains (maybe the
random number generators fault). The viewing plane is not
quite right as the original code used SetViewportOrg() which there
doesn't seem to be an equivalent of under wxWidgets, and my quick
hack doesn't fix.
*/

#include "wx/wxprec.h"

#if !defined(WX_PRECOMP)
#  include "wx/wx.h"
#endif //precompiled headers

#include "wx/stockitem.h"

#include <array>
#include <chrono>
#include <clocale>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <random>

namespace
{
    constexpr bool IsWindows()
    {
#if defined(_WIN32) || defined(_WIN64)
        return true;
#else
        return false;
#endif
    }

    const char* GetLocaleNameForSetLocale()
    {
        if (IsWindows())
        {
            return ".UTF-8";
        }
        return "";
    }

    std::mt19937& Rng()
    {
        static std::mt19937 rng{};
        return rng;
    }

    void Randomize()
    {
        const auto now{std::chrono::system_clock::now().time_since_epoch()};
        const auto seed{static_cast<std::uint32_t>(
            std::chrono::duration_cast<std::chrono::milliseconds>(now).count())};
        Rng().seed(seed);
    }

    int RandomInt(int maxExclusive)
    {
        std::uniform_int_distribution<int> dist{0, maxExclusive - 1};
        return dist(Rng());
    }

    int BeforeMain()
    {
    #if defined(__WXGTK__)
        namespace fs = std::filesystem;
        wxString fontConfigPath{};
        fs::path fontsDir{"/etc/fonts"};
        if (!wxGetEnv("FONTCONFIG_PATH", &fontConfigPath) && fs::is_directory(fontsDir))
        {
            wxSetEnv("FONTCONFIG_PATH", wxString::FromUTF8(fontsDir.string()));
        }
    #endif
        return 0;
    }
    int beforeMain = BeforeMain();

}

static int detail = 9; // CHANGE THIS... 7,8,9 etc

static bool running{false};
static wxMenuBar* menuBar{nullptr};

// Define a new application type
class MyApp: public wxApp
{
public:
    MyApp() = default;
    MyApp(const MyApp&) = delete;
    MyApp(MyApp&&) = delete;
    MyApp& operator=(const MyApp&) = delete;
    MyApp& operator=(MyApp&&) = delete;
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

// Define a new frame type
class MyFrame: public wxFrame
{
public:
    MyFrame(wxFrame* frame, const wxString& title, const wxPoint& pos, const wxSize& size);
    MyFrame() = delete;
    MyFrame(const MyFrame&) = delete;
    MyFrame(MyFrame&&) = delete;
    MyFrame& operator=(const MyFrame&) = delete;
    MyFrame& operator=(MyFrame&&) = delete;
    void OnCloseWindow(wxCloseEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnKeyDown(wxKeyEvent& event);
};

// Define a new canvas which can receive some events
class MyCanvas: public wxWindow
{
public:
    MyCanvas(wxFrame* frame);
    MyCanvas() = delete;
    MyCanvas(const MyCanvas&) = delete;
    MyCanvas(MyCanvas&&) = delete;
    MyCanvas& operator=(const MyCanvas&) = delete;
    MyCanvas& operator=(MyCanvas&&) = delete;
    void Draw(wxDC& dc);
private:
    void OnPaint(wxPaintEvent& event);
    void Fractal(wxDC& dc, int X1, int Y1, int X2, int Y2, int Z1, int Z2, int Z3, int Z4, int Iteration, double Std, double Ratio);
    wxPen SnowPen{};
    wxPen MtnPen{};
    wxPen GreenPen{};
    wxBrush WaterBrush{};
    int SeaLevel{};
};

// `Main program' equivalent, creating windows and returning main app frame
bool MyApp::OnInit()
{
    std::setlocale(LC_ALL, GetLocaleNameForSetLocale());
#if defined(__WXGTK__)
    GTKSuppressDiagnostics();
#endif
    // Create the main frame window
    auto *frame{new MyFrame(nullptr, wxT("Fractal Mountains for wxWidgets"), wxDefaultPosition, wxSize(640, 480))};

    // Make a menubar
    auto *file_menu{new wxMenu};
    file_menu->Append(wxID_EXIT, wxGetStockLabel(wxID_EXIT));
    menuBar = new wxMenuBar;
    menuBar->Append(file_menu, wxT("&File"));
    frame->SetMenuBar(menuBar);

    (void) new MyCanvas(frame);

    // Show the frame
    frame->Show(true);

    return true;
}

// My frame constructor
MyFrame::MyFrame(wxFrame* frame, const wxString& title, const wxPoint& pos, const wxSize& size):
    wxFrame(frame, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE | wxFULL_REPAINT_ON_RESIZE )
{
    Bind(wxEVT_CHAR_HOOK, &MyFrame::OnKeyDown, this);
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnCloseWindow, this);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Destroy();
}

void MyFrame::OnCloseWindow(wxCloseEvent& WXUNUSED(event))
{
    static bool destroyed{false};
    if (destroyed)
    {
        return;
    }
    Destroy();
    destroyed = true;
}

void MyFrame::OnKeyDown(wxKeyEvent& event)
{
    if (event.GetKeyCode() == WXK_F5)
    {
        Refresh();
        Update(); 
        return;
    }
    event.Skip();
}

// Define a constructor for my canvas
MyCanvas::MyCanvas(wxFrame* frame):
    wxWindow(frame, wxID_ANY)
{
    Bind(wxEVT_PAINT, &MyCanvas::OnPaint, this);

    wxColour wxCol1{255, 255, 255};
    SnowPen = wxPen(wxCol1, 2);

    wxColour wxCol2{128, 0, 0};
    MtnPen = wxPen(wxCol2);

    wxColour wxCol3{0, 128, 0};
    GreenPen = wxPen(wxCol3);

    wxColour wxCol4{0, 0, 128};
    WaterBrush = wxBrush(wxCol4);
}

void MyCanvas::OnPaint(wxPaintEvent& WXUNUSED(event))
{
    wxPaintDC dc{this};
    PrepareDC(dc);
    Draw(dc);
}

void MyCanvas::Draw(wxDC& dc)
{
    if (running)
    {
        return;
    }

    running = true;
    menuBar->EnableTop(0, false);

    Randomize();

    dc.SetBackground(*wxLIGHT_GREY_BRUSH);
    dc.Clear();

    int Left{0};
    int Top{0};
    int Right{0};
    int Bottom{0};
    GetClientSize(&Right, &Bottom);

    Right *= 3; Right /= 4;
    Bottom *= 3; Bottom /= 4;
    Left = 0;
    Top = Bottom/8;

    std::array<wxPoint, 4> Water{{
        wxPoint{Left, Top},
        wxPoint{Right, Top},
        wxPoint{Right + Bottom / 2, Bottom},
        wxPoint{Bottom / 2, Bottom}
    }};

    dc.SetBrush(WaterBrush);
    dc.DrawPolygon(4, Water.data());

    double H{0.75};
    double Scale{static_cast<double>(Bottom)};
    double Ratio{1.0 / std::pow(2.0, H)};
    double Std{Scale * Ratio};
    SeaLevel = RandomInt(18) - 8;

    Fractal(dc, Left, Top, Right, Bottom, 0, 0, 0, 0, detail, Std, Ratio);

    menuBar->EnableTop(0, true);
    running = false;
}

void MyCanvas::Fractal(wxDC& dc, int X1, int Y1, int X2, int Y2, int Z1, int Z2, int Z3, int Z4, int Iteration, double Std, double Ratio)
{
    int Xmid{(X1 + X2) / 2};
    int Ymid{(Y1 + Y2) / 2};
    int Z23{(Z2 + Z3) / 2};
    int Z41{(Z4 + Z1) / 2};
    int Newz{static_cast<int>((Z1 + Z2 + Z3 + Z4) / 4 + (static_cast<double>(RandomInt(17) - 8) / 8.0) * Std)};

    if (--Iteration)
    {
        int Z12{(Z1 + Z2) / 2};
        int Z34{(Z3 + Z4) / 2};
        double Stdmid{Std * Ratio};

        Fractal(dc, Xmid, Y1, X2, Ymid, Z12, Z2, Z23, Newz, Iteration, Stdmid, Ratio);
        Fractal(dc, X1, Y1, Xmid, Ymid, Z1, Z12, Newz, Z41, Iteration, Stdmid, Ratio);
        Fractal(dc, Xmid, Ymid, X2, Y2, Newz, Z23, Z3, Z34, Iteration, Stdmid, Ratio);
        Fractal(dc, X1, Ymid, Xmid, Y2, Z41, Newz, Z34, Z4, Iteration, Stdmid, Ratio);
    }
    else
    {
        if (Newz <= SeaLevel)
        {
            std::array<wxPoint, 4> P{{
                wxPoint{Y1 / 2 + X1, Y1 + Z1},
                wxPoint{Y1 / 2 + X2, Y1 + Z2},
                wxPoint{Y2 / 2 + X2, Y2 + Z3},
                wxPoint{Y2 / 2 + X1, Y2 + Z4}
            }};

            dc.SetPen(* wxBLACK_PEN);
            dc.SetBrush(* wxBLACK_BRUSH);

            dc.DrawPolygon(4, P.data());

            if (Z1 >= -(60 + RandomInt(25)))
            {
                dc.SetPen(GreenPen);
            }
            else if (Z1 >= -(100 + RandomInt(25)))
            {
                dc.SetPen(MtnPen);
            }
            else
            {
                dc.SetPen(SnowPen);
            }

            dc.DrawLine(Ymid/2+X2, Ymid+Z23, Ymid/2+X1, Ymid+Z41);
        }
    }
}
