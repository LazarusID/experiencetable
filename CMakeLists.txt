cmake_minimum_required(VERSION 3.7)

project(experiencetab LANGUAGES cpp)

add_subdirectory(yaml-cpp)

add_executable(${PROJECT_NAME}

	experienceevent.cpp main.cpp
)

add_dependency(${PROJECT_NAME}
	yamlcpp
	)
target_link_library(${PROJECT_NAME} yamlcpp)
