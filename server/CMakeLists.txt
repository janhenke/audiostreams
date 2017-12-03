
list(APPEND SERVER_SOURCE_FILES temp.cpp)

add_library(audiostreams_server ${SERVER_SOURCE_FILES})
set_target_properties(audiostreams_server PROPERTIES VERSION 0.1 SOVERSION 0)
target_link_libraries(audiostreams_server audiostreams_common ${PROJECT_LINK_LIBRARIES})