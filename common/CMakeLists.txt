include(GenerateExportHeader)

## Threading
find_package(Threads REQUIRED)
list(APPEND PROJECT_LINK_LIBRARIES Threads::Threads)

find_package(Protobuf)
include_directories(${Protobuf_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
# configure config.h from build system properties
configure_file(config.hpp.cmake config.hpp)

PROTOBUF_GENERATE_CPP(PROTO_SOURCE_FILES PROTO_HEADER_FILES audiostreams.proto)

add_library(audiostreams_proto ${PROTO_SOURCE_FILES} ${PROTO_HEADER_FILES})
set_target_properties(audiostreams_proto PROPERTIES
                      VERSION ${AUDIOSTREAMS_PROTO_VERSION}
                      SOVERSION ${AUDIOSTREAMS_PROTO_SOVERSION}
					  WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_link_libraries(audiostreams_proto ${PROJECT_LINK_LIBRARIES} ${PROTOBUF_LIBRARY})
list(APPEND PROJECT_LINK_LIBRARIES audiostreams_proto)

list(APPEND COMMON_SOURCE_FILES ${CMAKE_CURRENT_BINARY_DIR}/config.hpp)
list(APPEND COMMON_SOURCE_FILES ${CMAKE_CURRENT_BINARY_DIR}/audiostreams_export.h)
list(APPEND COMMON_SOURCE_FILES version.cpp version.hpp)

add_library(audiostreams_common STATIC ${COMMON_SOURCE_FILES})
target_link_libraries(audiostreams_common ${PROJECT_LINK_LIBRARIES})

GENERATE_EXPORT_HEADER(audiostreams_common BASE_NAME AUDIOSTREAMS)
