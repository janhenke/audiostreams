
list(APPEND CLIENT_SOURCE_FILES temp.cpp)

add_library(audiostreams_client ${CLIENT_SOURCE_FILES})

target_link_libraries(audiostreams_client audiostreams_common)