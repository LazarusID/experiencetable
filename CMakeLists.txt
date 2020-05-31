cmake_minimum_required(VERSION 3.17)


project(experiencetable LANGUAGES CXX VERSION 0.8)

include(FetchContent)
include(CTest)

cmake_policy(SET CMP0077 NEW)
configure_file(installer.nsis.in installer.nsi)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)


set(YAML_CPP_BUILD_TESTS off)
set(YAML_CPP_BUILD_TOOLS off)
set(YAML_CPP_INSTALL off)

FetchContent_Declare(
	yamlcpp
	GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
	GIT_TAG yaml-cpp-0.6.3
)

FetchContent_GetProperties(yamlcpp)
if (NOT yamlcpp_POPULATED)
	FetchContent_Populate(yamlcpp)
	cmake_policy(SET CMP0077 NEW)
	add_subdirectory(${yamlcpp_SOURCE_DIR} ${yamlcpp_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(${PROJECT_NAME}
	experienceevent.cpp 
	main.cpp
	gameday.cpp 
	gameday.h
	daysummary.cpp
)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

add_subdirectory(test)

add_dependencies(${PROJECT_NAME}
	yaml-cpp
	)
target_link_libraries(${PROJECT_NAME} yaml-cpp)

set(EXAMPLE_DIR ${PROJECT_SOURCE_DIR}/examples)

set(TEST_OUTPUT ${PROJECT_SOURCE_DIR}/testoutput.sh)

add_test(NAME load-1-file 
	COMMAND ${TEST_OUTPUT} ${EXAMPLE_DIR}/experience.yaml ${EXAMPLE_DIR}/oneday.txt
)

add_test(NAME load-campaign
	COMMAND ${TEST_OUTPUT} ${EXAMPLE_DIR} ${EXAMPLE_DIR}/campaign.txt
)
