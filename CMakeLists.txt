cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 99)

add_library(MCP4822 STATIC MCP4822.c)
target_include_directories(MCP4822 PUBLIC .)