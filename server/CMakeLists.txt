
list(APPEND SERVER_SOURCE_FILES temp.cpp)

add_library(audiostreams_server ${SERVER_SOURCE_FILES})
set_target_properties(audiostreams_server PROPERTIES
                      VERSION ${AUDIOSTREAMS_SERVER_VERSION}
                      SOVERSION ${AUDIOSTREAMS_SERVER_SOVERSION})
target_link_libraries(audiostreams_server audiostreams_common ${PROJECT_LINK_LIBRARIES})