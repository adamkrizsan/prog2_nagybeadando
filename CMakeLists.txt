cmake_minimum_required( VERSION 3.11 )

project( ITK_graphicslib )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package( SDL2 REQUIRED )

include_directories(include)

link_libraries (
  SDL2
  SDL2_ttf
)

add_library( graphics graphics.cpp )


add_executable( test_graphics main.cpp  )
target_link_libraries( test_graphics graphics pthread)

add_executable( helloworld helloworld.cpp Table.cpp Tile.cpp)
target_link_libraries( helloworld graphics)
