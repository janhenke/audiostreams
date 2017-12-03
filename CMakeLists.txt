cmake_minimum_required(VERSION 3.7)

project(audiostreams VERSION 0.0.1 LANGUAGES C CXX)

# compile for C++17 without compiler extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_EXTENSIONS OFF)
# compile for C11 without compiler extensions
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

option(BUILD_SHARED_LIBS "Build shared librarys." ON)
option(USE_NETWORK_STACK "Enable the library's internal network code, adds dependency on Boost ASIO." ON)

## if either the client or server library is build, we also build the internal common library
set(BUILD_COMMON_LIBRARY (${BUILD_CLIENT_LIBRARY} OR ${BUILD_SERVER_LIBRARY}))

# find project dependencies and configure them
find_package(Doxygen)

add_subdirectory(common)
include_directories(common)
include_directories(${PROJECT_BUILD_DIR}/common)

add_subdirectory(client)

add_subdirectory(server)

add_subdirectory(test EXCLUDE_FROM_ALL)

add_subdirectory(examples EXCLUDE_FROM_ALL)

