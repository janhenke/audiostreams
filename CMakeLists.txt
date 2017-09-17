cmake_minimum_required(VERSION 3.7)

project(audiostreams VERSION 0.0.1 LANGUAGES C CXX)

# compile for C++17 without extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
# compile for C11 without extensions
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)

# include current source and binary directory by default
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

# enable extra warnings
if (${UNIX})
	add_compile_options(-Wall -Wextra -Werror -Wpedantic)
elseif (${WIN32})
	add_compile_options(/W4 /WX /EHsc)
endif ()

# project options
## Use libc++ instead of libstdc++ (Clang only)
if (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
	option(USE_LIBCPP "Use libc++ as C++ standard library" OFF)
	if (USE_LIBCPP)
		add_compile_options(-stdlib=libc++)
	endif ()
endif ()

option(BUILD_CLIENT_LIBRARY "Build the client library." ON)
option(BUILD_SERVER_LIBRARY "Build the server library." ON)
option(BUILD_TESTS "Build the tests." ON)
option(BUILD_EXAMPLES "Build the examples." ON)

option(BUILD_SHARED_LIBS "Build shared librarys." ON)
option(USE_NETWORK_STACK "Enable the library's internal network code, adds dependency on Boost ASIO." ON)

## if either the client or server library is build, we also build the internal common library
if(${BUILD_CLIENT_LIBRARY} OR ${BUILD_SERVER_LIBRARY})
	set(BUILD_COMMON_LIBRARY TRUE)
else()
	set(BUILD_COMMON_LIBRARY FALSE)
endif()

# configure config.h from build system properties
configure_file(config.h.cmake config.h)

# find project dependencies and configure them
find_package(Doxygen)

include(GenerateExportHeader)

## Threading
find_package(Threads REQUIRED)
list(APPEND PROJECT_LIBRARY_DEPENDECIES Threads::Threads)

if(${BUILD_COMMON_LIBRARY})
	add_subdirectory(common)
	include_directories(common)
	include_directories(${PROJECT_BUILD_DIR}/common)
endif()

if(${BUILD_CLIENT_LIBRARY})
	add_subdirectory(client)
endif()

if(${BUILD_SERVER_LIBRARY})
	add_subdirectory(server)
endif()

if(${BUILD_TESTS})
	add_subdirectory(test)
endif()

if(${BUILD_EXAMPLES})
	add_subdirectory(examples)
endif()

