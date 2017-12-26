cmake_minimum_required(VERSION 3.9)

project(audiostreams VERSION 0.0.1 LANGUAGES C CXX)

# compile for C++17 without compiler extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_EXTENSIONS OFF)
# compile for C11 without compiler extensions
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED 11)
set(CMAKE_C_EXTENSIONS OFF)

set(AUDIOSTREAMS_PROTO_SOVERSION 0)
set(AUDIOSTREAMS_CLIENT_SOVERSION 0)
set(AUDIOSTREAMS_SERVER_SOVERSION 0)

# enable extra warnings
if (${UNIX})
	add_compile_options(-Wall -Wextra -Wpedantic)
elseif (${WIN32})
	add_compile_options(/W4 /EHsc)
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

add_subdirectory(src)

add_subdirectory(test EXCLUDE_FROM_ALL)

add_subdirectory(examples EXCLUDE_FROM_ALL)

