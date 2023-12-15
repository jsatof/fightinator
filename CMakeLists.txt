cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(fightinator VERSION 0.1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

# Finding System Deps
find_package(PkgConfig REQUIRED)
pkg_check_modules(CRITERION REQUIRED criterion)
pkg_check_modules(SDL2 REQUIRED sdl2)
# TODO(james): add opengl

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG} -Og -Wall -Wextra -Werror=deprecated-declarations -fdiagnostics-color=always")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall -Wextra -Werror -fdiagnostics-color=always")

# for use with clang tidy and clang format
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CLANG_TIDY NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY}" "--config-file=${PROJECT_SOURCE_DIR}/.clang-tidy")

find_program(CLANG_FORMAT NAMES "clang-format")
set(CLANG_FORMAT_COMMAND "${CLANG_FORMAT}") # default is `--style=file`, where it looks for `.clang-format` in parent dir

add_subdirectory(src)
add_subdirectory(test)
