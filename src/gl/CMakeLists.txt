add_library(gl gl.h) # add library

target_include_directories(gl
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

add_library(color STATIC
              color.cxx
              )

add_library(framebuffer STATIC
              framebuffer.cxx
              )

add_library(pixel STATIC
              pixel.cxx
              )

target_link_libraries(gl PUBLIC color)
target_link_libraries(gl PUBLIC framebuffer)
target_link_libraries(gl PUBLIC pixel)