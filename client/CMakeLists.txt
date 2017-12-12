
list(APPEND CLIENT_SOURCE_FILES temp.cpp)

add_library(audiostreams_client ${CLIENT_SOURCE_FILES})
set_target_properties(audiostreams_client PROPERTIES
                      VERSION ${AUDIOSTREAMS_CLIENT_VERSION}
                      SOVERSION ${AUDIOSTREAMS_CLIENT_SOVERSION})
target_link_libraries(audiostreams_client audiostreams_common ${PROJECT_LINK_LIBRARIES})