About

-----



wxWidgets is a free and open source cross-platform C++ framework for writing advanced GUI applications using native controls.



!\[wxWidgets Logo](https://www.wxwidgets.org/assets/img/header-logo.png)



wxWidgets allows you to write native-looking GUI applications for all the major desktop platforms and also helps with abstracting

the differences in the non-GUI aspects between them. It is free for the use in both open source and commercial applications, comes

with the full, easy to read and modify, source and extensive documentation and a collection of more than a hundred examples.



You can learn more about wxWidgets at \[https://www.wxwidgets.org/](https://www.wxwidgets.org/) and read its documentation online at \[https://docs.wxwidgets.org/](https://docs.wxwidgets.org/).



This Repository

---------------



This repository contains sample programs for wxWidgets with a \[CMake](https://cmake.org/) build system. Most of the sample programs come from the \[official wxWidgets source code repository](https://github.com/wxWidgets/).



Licence

-------



\[wxWidgets licence](https://github.com/wxWidgets/wxWidgets/blob/master/docs/licence.txt) is a modified version of LGPL explicitly allowing not distributing the sources of an application using the library even in the case of static inking.



Building

--------



The \[CMake](https://cmake.org/) build system for this repository assummes wxWidgets is already installed, perhaps via \[VCPKG](https://vcpkg.io/). To build the samples simply use the standard CMake build commands to configure and build the projects.



The following is a list of steps for building the project using \[Visual Studio Code](https://code.visualstudio.com/).



1. Create c\_cpp\_properties.json and settings.json to configure \[Visual Studio Code](https://code.visualstudio.com/) to support your compiler and using wxWidgets.
2. Run the "CMake: Select a Kit" command.
3. Run the "CMake: Select Variant" command.
4. Run the "CMake: Configure" command.
5. Run the "CMake: Build" command.





