cmake_minimum_required(VERSION 3.10)

project (Rasterizer VERSION 1.0) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(RasterizerConfig.h.in src/RasterizerConfig.h) # generate config file

# add the libraries
add_subdirectory(src/MathFunctions) 

# add the executable
add_executable(${PROJECT_NAME} src/main.cxx)

# link the libraries
target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)

# add the binary tree to the search path for include files
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/src/MathFunctions")


# | building tips:
# | 1. create a build directory
# | 2. cd build
# | 3. cmake ../
# | 4. cmake --build .
# | 5. ./<executable name> <args>
# | tip: after you make steps 1 to 4 once, in order to build it again is only needed to run step 4. REMEMBER TO BE IN THE CORRECT DIRECTORY.