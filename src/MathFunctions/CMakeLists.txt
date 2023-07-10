add_library(MathFunctions MathFunctions.cxx) # add library

target_include_directories(MathFunctions
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
                           )

add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

target_link_libraries(MathFunctions PUBLIC SqrtLibrary)