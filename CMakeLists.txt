cmake_minimum_required(VERSION 3.24...3.30)
project(rayrog)

include(FetchContent)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 6.0)

FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(raylib)

# Project code
INCLUDE_DIRECTORIES(
        ${CMAKE_SOURCE_DIR}/extlib/random
        ${CMAKE_SOURCE_DIR}/extlib/json
)

#INCLUDE_DIRECTORIES("extlib/raylib-cpp/include/")

# Our Project
add_executable(${PROJECT_NAME})
add_subdirectory(src)

set(CMAKE_CXX_STANDARD 23)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)


#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)