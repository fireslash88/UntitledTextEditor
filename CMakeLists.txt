cmake_minimum_required(VERSION 4.3)
project(TextEditor)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/Debug)

# Fetch and compile Raylib
set(RAYLIB_VERSION 6.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
            set(FETCH CONTENT_QUIET NO)
            FetchContent_MakeAvailable(raylib)
            set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    endif()
endif()


# Include files in the src
add_executable(TextEditor
        src/main.cpp
        src/editor.h
        src/editor.cpp
        src/config.h
)

# Include eventual directories
target_include_directories(${PROJECT_NAME} PRIVATE
        fonts
)

# Include raylib library
target_link_libraries(${PROJECT_NAME} raylib)
