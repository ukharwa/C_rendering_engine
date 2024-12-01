cmake_minimum_required(VERSION 3.31)

project(C_Rendering_Engine)

add_executable(main main.c shapes.c vertex_shader.c pipeline.c buffer.c vector.c)

target_link_libraries(main PRIVATE m)
target_link_libraries(main PRIVATE SDL2)
