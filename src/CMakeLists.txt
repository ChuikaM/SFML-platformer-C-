cmake_minimum_required(VERSION 3.28)

project(SFMLPlatformer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/SFML)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG        2.5.0
)
FetchContent_MakeAvailable(SFML)

set(PROJECT_SOURCES
    Source.cpp
	Functions.h
	Map.h
	SomeClasses.h
	texMap.h
	View.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/${PROJECT_SOURCES}
)

message(" Mwsss ${PROJECT_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-graphics sfml-main sfml-audio)

add_custom_command(
        TARGET ${PROJECT_NAME}  POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
                ${PROJECT_SOURCE_DIR}/CyrilicOld.TTF
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/CyrilicOld.TTF	
		COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/Images
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Images
		COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/Sounds
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Sounds	
)