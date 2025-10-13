cmake_minimum_required(VERSION 3.16)

project(SFMLPlatformer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "./SFML")

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

set(PROJECT_SOURCES
    Source.cpp
	Functions.h
	Map.h
	SomeClasses.h
	texMap.h
	View.h
)

add_executable(SFMLPlatformer
    ${PROJECT_SOURCES}
)

target_link_libraries(SFMLPlatformer PRIVATE sfml-window sfml-graphics sfml-main sfml-audio)