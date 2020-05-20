include(GoogleTest)

set(TEST_NAME ${PROJECT_NAME}-test)

include_directories(..)

file(GLOB TEST_SOURCES
        "*.cpp"
        )

set(SUT
        ../daysummary.cpp
        ../gameday.cpp
        ../experienceevent.cpp
        )

add_executable(${TEST_NAME}
        ${TEST_SOURCES}
        ${SUT}
        )
target_link_libraries(${TEST_NAME}
        gtest
        gtest_main
        yaml-cpp
        )
target_compile_features(${TEST_NAME} PUBLIC cxx_override)

gtest_discover_tests(${TEST_NAME})
