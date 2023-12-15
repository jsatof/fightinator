set(fightinator_SOURCES
	color.c
	physics.c
	ui.c
)

add_executable(${PROJECT_NAME} main.c ${fightinator_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# shared library for unit testing
add_library(fightinator_shared SHARED ${fightinator_SOURCES})
target_include_directories(fightinator_shared PRIVATE ${PROJECT_SOURCE_DIR}/src)
install(TARGETS fightinator_shared LIBRARY DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# Prepend the full path to each source file
# Create custom target for running clang tidy
list(TRANSFORM fightinator_SOURCES PREPEND ${CMAKE_SOURCE_DIR}/src/)

set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS}
    -extra-arg=-Wno-unknown-warning-option
    -extra-arg=-Wno-ignored-optimization-argument
    -extra-arg=-Wno-unused-command-line-argument
    -warning-as-errors=*)

if("${CLANG_TIDY_OPTIONS_DRIVER_MODE}" STREQUAL "cl")
    set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS} -extra-arg=/std:c++${CMAKE_CXX_STANDARD})
else()
    set(CLANG_TIDY_OPTIONS ${CLANG_TIDY_OPTIONS} -extra-arg=-std=c++${CMAKE_CXX_STANDARD})
endif()

add_custom_target(tidy
    COMMAND clang-tidy -p ${CMAKE_BINARY_DIR} --config-file=${CMAKE_SOURCE_DIR}/.clang-tidy --use-color ${fightinator_SOURCES}
    COMMENT "Running tidy checks"
    VERBATIM)

add_custom_target(format
    COMMAND clang-format --Werror --sort-includes --verbose ${fightinator_SOURCES}
    COMMENT "Running formatting checks"
    VERBATIM)
