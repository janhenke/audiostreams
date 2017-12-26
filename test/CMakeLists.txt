enable_testing()

find_package(GTest REQUIRED)

add_executable(client_test client_test.cpp)
target_include_directories(client_test PRIVATE ${GTest_INCLUDE_DIRS})
target_link_libraries(client_test audiostreams_client GTest::GTest GTest::Main)
gtest_discover_tests(client_test)

add_executable(server_test server_test.cpp)
target_include_directories(server_test PRIVATE ${GTest_INCLUDE_DIRS})
target_link_libraries(server_test audiostreams_server GTest::GTest GTest::Main)
gtest_discover_tests(server_test)