if(NOT DEFINED LOGGER_LIBRARY)
  message(FATAL_ERROR "Please compile using the repo's root CMakeLists.txt")
endif()

set(D ${CMAKE_CURRENT_SOURCE_DIR})

set(LOGGER_SOURCES
  ${LOGGER_SOURCES}
  ${D}/AnsiConsoleLogger.cpp
  ${D}/Logger.cpp
  ${D}/LogInput.cpp
  ${D}/StdoutLogger.cpp
  PARENT_SCOPE
)
