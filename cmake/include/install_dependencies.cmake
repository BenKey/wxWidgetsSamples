file(GET_RUNTIME_DEPENDENCIES 
    EXECUTABLES "${TARGET_FILE}" 
    DIRECTORIES "${GPP_DIR}" 
    RESOLVED_DEPENDENCIES_VAR resolved_libs 
    UNRESOLVED_DEPENDENCIES_VAR unresolved_libs
)
list(FILTER unresolved_libs EXCLUDE REGEX "^api-ms-win")
foreach(unresolved IN LISTS unresolved_libs)
  message(WARNING "The following dependency could not be resolved: ${unresolved}")
endforeach()
foreach(lib IN LISTS resolved_libs)
  file(INSTALL "${lib}" DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
endforeach()
