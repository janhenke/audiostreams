# find project dependencies and configure them
find_package(Doxygen)

find_package(Protobuf)
include_directories(${Protobuf_INCLUDE_DIRS})

find_package(Threads REQUIRED)

## Boost ASIO depends on Boost System
find_package(Boost 1.61 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

# compile our proto file to one library
protobuf_generate_cpp(PROTO_SOURCE_FILES PROTO_HEADER_FILES audiostreams.proto)
add_library(audiostreams_proto ${PROTO_SOURCE_FILES} ${PROTO_HEADER_FILES})
set_target_properties(audiostreams_proto PROPERTIES
                      VERSION ${AUDIOSTREAMS_PROTO_VERSION}
                      SOVERSION ${AUDIOSTREAMS_PROTO_SOVERSION}
                      # needed on Windows, otherwise the DLL exports nothing
                      WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_link_libraries(audiostreams_proto protobuf::libprotobuf-lite)

# configure config.h from build system properties
configure_file(config.hpp.cmake config.hpp)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(audiostreams_client config.hpp client.hpp client.cpp)
set_target_properties(audiostreams_client PROPERTIES
                      VERSION ${AUDIOSTREAMS_CLIENT_VERSION}
                      SOVERSION ${AUDIOSTREAMS_CLIENT_SOVERSION})
target_link_libraries(audiostreams_client audiostreams_proto Threads::Threads Boost::system)

add_library(audiostreams_server config.hpp server.hpp server.cpp)
set_target_properties(audiostreams_server PROPERTIES
                      VERSION ${AUDIOSTREAMS_SERVER_VERSION}
                      SOVERSION ${AUDIOSTREAMS_SERVER_SOVERSION})
target_link_libraries(audiostreams_server audiostreams_proto Threads::Threads Boost::system)