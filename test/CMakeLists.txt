find_package(Catch2 CONFIG REQUIRED)
include(CTest)
include(Catch)

if (BUILD_TESTING)
    set(ALL_TESTS
            all_tests
            #            two_sum_tests
            #            add_two_numbers_tests
    )
    file(GLOB tests_SRC CONFIGURE_DEPENDS "*.cpp")
    add_executable(all_tests ${tests_SRC})
    #add_executable(two_sum_tests two_sum_tests.cpp)
    #add_executable(add_two_numbers_tests add_two_numbers_tests.cpp)

    foreach (target ${ALL_TESTS})
        target_link_libraries(${target} PRIVATE Catch2::Catch2WithMain advent_of_code)
        add_test(NAME ${target} COMMAND ${target})
        catch_discover_tests(${target})
    endforeach ()
endif ()
