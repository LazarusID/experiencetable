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
	
set(EXAMPLE_DIR ${PROJECT_SOURCE_DIR}/examples)

set(TEST_OUTPUT ${PROJECT_SOURCE_DIR}/testoutput.sh)

add_test(NAME load-1-file 
	COMMAND ${TEST_OUTPUT} --source=${EXAMPLE_DIR}/experience.txt --expected=${EXAMPLE_DIR}/oneday.txt
)

add_test(NAME load-campaign
	COMMAND ${TEST_OUTPUT} --source=${EXAMPLE_DIR} --expected=${EXAMPLE_DIR}/campaign.txt
)

add_test(NAME markdown-day
		COMMAND ${TEST_OUTPUT} --markdown --source=${EXAMPLE_DIR}/experience.txt --expected=${EXAMPLE_DIR}/oneday.md
		)
