cmake_minimum_required(VERSION 3.22)

project(Chessie LANGUAGES C CXX)

find_package(PkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_NET REQUIRED SDL2_net)

include_directories(
  vendor
  source
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_TTF_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS}
  ${SDL2_MIXER_INCLUDE_DIRS}
  ${SDL2_NET_INCLUDE_DIRS}
)
link_directories(
  ${SDL2_LIBRARY_DIRS}
  ${SDL2_TTF_LIBRARY_DIRS}
  ${SDL2_IMAGE_LIBRARY_DIRS}
  ${SDL2_MIXER_LIBRARY_DIRS}
  ${SDL2_NET_LIBRARY_DIRS}
)

file(GLOB COMMON_SOURCE_FILES source/**.cpp)

# Client target
file(GLOB_RECURSE CLIENT_SOURCE_FILES source/client/**.cpp vendor/SDL_FontCache.c)
add_executable(client  ${COMMON_SOURCE_FILES} ${CLIENT_SOURCE_FILES})
target_link_libraries(
  client
  ${SDL2_LIBRARIES}
  ${SDL2_TTF_LIBRARIES}
  ${SDL2_IMAGE_LIBRARIES}
  ${SDL2_MIXER_LIBRARIES}
  ${SDL2_NET_LIBRARIES}
)

# Server target
file(GLOB_RECURSE SERVER_SOURCE_FILES source/server/**.cpp)
add_executable(server ${COMMON_SOURCE_FILES} ${SERVER_SOURCE_FILES})
target_link_libraries(server ${SDL2_LIBRARIES} ${SDL2_NET_LIBRARIES})