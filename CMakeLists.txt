cmake_minimum_required(VERSION 3.12)
project(ikarus)

set(CMAKE_CXX_STANDARD 14)

# boost
find_package(Boost 1.67.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(ikarus main.cpp src/serial_io.h src/serial_io.cpp src/either.h)

if(Boost_FOUND)
    target_link_libraries(ikarus ${Boost_LIBRARIES})
endif()

add_subdirectory(test)