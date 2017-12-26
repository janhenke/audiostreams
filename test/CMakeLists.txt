enable_testing()

find_package(GTest REQUIRED)

add_executable(client_test client_test.cpp)
target_include_directories(client_test PRIVATE ${GTest_INCLUDE_DIRS})
target_link_libraries(client_test PRIVATE audiostreams_client GTest::GTest GTest::Main)
# Requires cmake 3.10, enable when that version is commonly used
#gtest_discover_tests(client_test)
gtest_add_tests(TARGET client_test)

add_executable(server_test server_test.cpp)
target_include_directories(server_test PRIVATE ${GTest_INCLUDE_DIRS})
target_link_libraries(server_test PRIVATE audiostreams_server GTest::GTest GTest::Main)
# Requires cmake 3.10, enable when that version is commonly used
#gtest_discover_tests(server_test)
gtest_add_tests(TARGET server_test)