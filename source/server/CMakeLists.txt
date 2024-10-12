find_package(PkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_NET REQUIRED SDL2_net)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_NET_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS} ${SDL2_NET_LIBRARY_DIRS})

file(GLOB_RECURSE SERVER **.cpp)
add_executable(chessies ${COMMON} ${SERVER})

target_link_libraries(chessies ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_NET_LIBRARIES})