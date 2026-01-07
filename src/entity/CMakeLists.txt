cmake_minimum_required(VERSION 3.25)

project(entity)

file(GLOB ENTITY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(${PROJECT_NAME} STATIC ${ENTITY_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Audio)