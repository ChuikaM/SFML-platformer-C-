cmake_minimum_required(VERSION 3.25)
project(SFML_PLATFORMER_2D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

add_subdirectory(src/entity)
add_subdirectory(src/map_loader)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SFML::System SFML::Window SFML::Graphics SFML::Audio map_loader entity
)
if(EXISTS ${CMAKE_SOURCE_DIR}/src/img)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/src/img
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/img
        COMMENT "Copying img/ folder to build directory"
    )
endif()
if(EXISTS ${CMAKE_SOURCE_DIR}/src/fonts)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/src/fonts
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/fonts
        COMMENT "Copying fonts/ folder to build directory"
    )
endif()
if(EXISTS ${CMAKE_SOURCE_DIR}/src/maps)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/src/maps
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/maps
        COMMENT "Copying maps/ folder to build directory"
    )
endif()