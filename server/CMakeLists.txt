
list(APPEND SERVER_SOURCE_FILES temp.cpp)

add_library(audiostreams_server ${SERVER_SOURCE_FILES})

target_link_libraries(audiostreams_server audiostreams_common)