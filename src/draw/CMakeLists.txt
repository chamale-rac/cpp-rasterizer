add_library(draw draw.cxx) # add library

target_include_directories(draw
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )


add_library(line STATIC
              line.cxx
              )
              
target_include_directories(line PUBLIC ../gl)

add_library(polygon STATIC 
                polygon.cxx
                )   
                
target_include_directories(polygon PUBLIC ../gl)

target_link_libraries(draw PUBLIC line polygon gl)