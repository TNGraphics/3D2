cmake_minimum_required(VERSION 3.0)

project(project_3D2 VERSION 0.1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
#	For static linking
#	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
endif ()

configure_file(src/build_util/constants.hpp.in constants.hpp)

add_executable(project_3D2
			   src/main.cpp
			   )

if (CMAKE_BUILD_TYPE MATCHES Debug)
	target_compile_definitions(project_3D2 PUBLIC -DDEBUG=1)
endif()

if(DEFINED MEMORY_DEBUG AND MEMORY_DEBUG)
	target_compile_definitions(project_3D2 PUBLIC -DMEM_DEBUG)
endif()

target_include_directories(project_3D2 PRIVATE
						   ${PROJECT_BINARY_DIR}
						   )
