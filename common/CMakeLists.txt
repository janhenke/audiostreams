
# configure config.h from build system properties
configure_file(config.hpp.cmake config.hpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

list(APPEND COMMON_SOURCE_FILES ${CMAKE_CURRENT_BINARY_DIR}/config.hpp)
list(APPEND COMMON_SOURCE_FILES ${CMAKE_CURRENT_BINARY_DIR}/audiostreams_export.h)
list(APPEND COMMON_SOURCE_FILES version.cpp version.hpp)

add_library(audiostreams STATIC ${COMMON_SOURCE_FILES})

GENERATE_EXPORT_HEADER(audiostreams BASE_NAME AUDIOSTREAMS)
