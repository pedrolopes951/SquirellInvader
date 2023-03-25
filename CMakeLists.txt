cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


project(Squirell)

# Add the include directory
include_directories(include)


#Add fonts dierectory 

# Create the fonts directory in the binary directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/fonts)   


file(COPY ${CMAKE_SOURCE_DIR}/fonts/
    DESTINATION ${CMAKE_BINARY_DIR}/fonts/)


# Tell CMake that the fonts directory should be included in the install step
install(DIRECTORY ${CMAKE_BINARY_DIR}/fonts/
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)

# Create the texture directory in the binary directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/texture/)  

 
file(COPY ${CMAKE_SOURCE_DIR}/texture/ 
    DESTINATION ${CMAKE_BINARY_DIR}/texture/)


# Tell CMake that the texture directory should be included in the install step 
install(DIRECTORY ${CMAKE_BINARY_DIR}/texture 
    DESTINATION ${CMAKE_INSTALL_PREFIX}
)  

add_definitions(-DTEXTUREPATH="${CMAKE_BINARY_DIR}/texture/")
add_definitions(-DFONTPATH="${CMAKE_BINARY_DIR}/fonts/")


# Add the source files
file(GLOB SOURCES "src/*.cpp")


# Find SFML library
find_package(SFML 2.5 REQUIRED system window graphics network audio)
set(SFML_LIBS sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

include_directories(${SFML_INCLUDE_DIR})

# Add the executable directory
add_subdirectory(executable)

# Create the precompiled header
set(PCH_HEADER "include/stdafx.hpp")
set(PCH_SOURCE "src/stdafx.cpp")
set(PCH_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(MyPCH STATIC ${PCH_SOURCE})
target_include_directories(MyPCH PUBLIC ${PCH_INCLUDE_DIRS})
target_compile_features(MyPCH PUBLIC cxx_std_11)
target_compile_options(MyPCH PRIVATE -Winvalid-pch)
target_precompile_headers(MyPCH PUBLIC ${PCH_HEADER})




# Add the executable
add_library(gamelib STATIC ${SOURCES})
