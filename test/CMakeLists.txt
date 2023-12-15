set(fightinator_TEST_SOURCES
    test.c)

add_executable(fightinator_test ${fightinator_TEST_SOURCES})
target_include_directories(fightinator_test PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_directories(fightinator_test PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(fightinator_test PRIVATE fightinator_shared criterion)

add_custom_target(test COMMAND fightinator_test)
