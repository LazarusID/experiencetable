include(GoogleTest)

include_directories(..)

file(GLOB TEST_SOURCES
        "*.cpp"
        )

add_executable(daysummary-test
        ../daysummary.cpp
        test_daysummary.cpp
        )
add_executable(experienceevent-test
        ../experienceevent.cpp
        test_experienceevent.cpp
        )

set_property(TARGET daysummary-test PROPERTY CXX_STANDARD 17)
set_property(TARGET experienceevent-test PROPERTY CXX_STANDARD 17)

add_test(NAME ExperienceEvent
        COMMAND experiencevent-test)
add_test(NAME DaySummary
        COMMAND daysummary-test)