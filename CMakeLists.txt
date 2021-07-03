cmake_minimum_required(VERSION 3.16)


project(experiencetable LANGUAGES CXX VERSION 1.1)

include(FetchContent)
include(CTest)

cmake_policy(SET CMP0077 NEW)
configure_file(installer.nsis.in installer.nsi)

add_executable(${PROJECT_NAME}
	experienceevent.cpp 
	main.cpp
	gameday.cpp 
	gameday.h
	daysummary.cpp
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

add_subdirectory(test)
	
set(EXAMPLE_DIR ${PROJECT_SOURCE_DIR}/examples/src)
set(EXPECTED_DIR ${PROJECT_SOURCE_DIR}/examples/expected)

set(TEST_OUTPUT ${PROJECT_BINARY_DIR}/test/compareoutput${CMAKE_EXECUTABLE_SUFFIX})
set(SYSTEM_UNDER_TEST ${PROJECT_BINARY_DIR}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX})

add_test(NAME load-1-file 
	COMMAND ${SYSTEM_UNDER_TEST} ${EXAMPLE_DIR}/experience.txt | ${TEST_OUTPUT} ${EXPECTED_DIR}/oneday.txt
)

add_test(NAME load-campaign
	COMMAND ${SYSTEM_UNDER_TEST} ${EXAMPLE_DIR} | ${TEST_OUTPUT} ${EXPECTED_DIR}/campaign.txt
)

add_test(NAME markdown-day
		COMMAND ${SYSTEM_UNDER_TEST} --markdown ${EXAMPLE_DIR}/experience.txt | ${TEST_OUTPUT} ${EXPECTED_DIR}/oneday.md
		)
