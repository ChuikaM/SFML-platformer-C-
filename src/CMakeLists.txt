cmake_minimum_required(VERSION 3.4 3.12)

project(SFMLPlatformer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG        2.5.0
)
FetchContent_MakeAvailable(SFML)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

set(PROJECT_SOURCES
    Source.cpp
	Functions.h
	Map.h
	SomeClasses.h
	texMap.h
	View.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-graphics sfml-main sfml-audio)