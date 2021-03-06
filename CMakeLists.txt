
cmake_minimum_required(VERSION 3.10)
project(Data-Structures-and-Algorithms)

set(CMAKE_CXX_STANDARD 20)

function(setup_target TARGET)
    if(MSVC)
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
        set(CMAKE_CXX_STANDARD 23)
    endif()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET})

    file(GLOB_RECURSE SRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET}/*.cpp)

    file(GLOB_RECURSE SRC_TOOLS
        ${CMAKE_CURRENT_SOURCE_DIR}/tools/*.cpp)

    add_executable(${TARGET} ${SRC_FILES} ${SRC_TOOLS})

    target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endfunction(setup_target TARGET)

setup_target(lab1-1)
setup_target(lab1-2)
setup_target(lab2-1)
setup_target(lab2-2)
setup_target(lab3-1)
setup_target(lab3-2)
setup_target(lab4)
setup_target(lab5)
setup_target(lab6)
