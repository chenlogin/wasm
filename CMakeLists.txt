cmake_minimum_required(VERSION 3.28)  
  
# 设置项目名称  
project(MyWebAssemblyProject)  
  
# 设置输入、输出目录  
MESSAGE(STATUS "CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
set(SRC ${CMAKE_SOURCE_DIR}/src)
set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dist)  

# 定义emcc的额外参数  
set(EMCC_EXTRA_FLAGS  
    --shell-file ${CMAKE_SOURCE_DIR}/html_template/index.html  
    -s EXPORTED_RUNTIME_METHODS=ccall,cwrap  
    -s EXPORTED_FUNCTIONS=_free,_malloc,_main,_processStr,_processArray,_processJson  
    -s NO_EXIT_RUNTIME=1  
)  

# 添加自定义命令来编译 C++ 文件为 WebAssembly  
add_custom_command(  
    OUTPUT ${OUTPUT_DIR}/index.html  
    COMMAND emcc ${EMCC_EXTRA_FLAGS} ${SRC}/main.cpp -o ${OUTPUT_DIR}/index.html 
    DEPENDS ${SRC}/main.cpp  
    COMMENT "Emscripten compiling main.cpp to WebAssembly"  
)  
  
# 添加一个伪目标，以便我们可以构建它  
add_custom_target(build_wasm ALL DEPENDS ${OUTPUT_DIR}/index.html)