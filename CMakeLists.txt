cmake_minimum_required(VERSION 3.13)

project(experiencetab LANGUAGES CXX)

include(FetchContent)
include(CTest)


set(YAML_CPP_BUILD_TESTS off)
set(YAML_CPP_BUILD_TOOLS off)
set(YAML_CPP_INSTALL off)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
	yamlcpp
	GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
	GIT_TAG yaml-cpp-0.6.3
)
FetchContent_MakeAvailable(yamlcpp)


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
target_link_libraries(${PROJECT_NAME} yaml-cpp stdc++)

set(EXAMPLE_DIR ${PROJECT_SOURCE_DIR}/examples)

set(TEST_OUTPUT ${PROJECT_SOURCE_DIR}/testoutput.sh)

add_test(NAME load-1-file 
	COMMAND ${TEST_OUTPUT} ${EXAMPLE_DIR}/experience.yaml ${EXAMPLE_DIR}/oneday.txt
)