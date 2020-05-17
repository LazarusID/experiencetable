cmake_minimum_required(VERSION 3.7)

project(experiencetab LANGUAGES CXX)

include(FetchContent)

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

	experienceevent.cpp main.cpp
)

add_dependencies(${PROJECT_NAME}
	yaml-cpp
	)
target_link_libraries(${PROJECT_NAME} yaml-cpp)
