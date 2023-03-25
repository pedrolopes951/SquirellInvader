# Add the executable
include_directories(${CMAKE_SOURCE_DIR}/include)

set(GameLib gamelib)


add_executable(Squirell main.cpp)


# Link the library to the executable
target_link_libraries(Squirell PUBLIC ${GameLib} ${SFML_LIBS})

