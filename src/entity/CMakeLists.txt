cmake_minimum_required(VERSION 3.25)

project(entity)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Audio)