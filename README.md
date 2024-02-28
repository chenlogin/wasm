- server
  - node服务，资源目录为emcc编译后的dist
  - npm run start
- emcc或者通过cmake生成wasm文件
  - emcc
    ```
    emcc src/main.cpp -o dist/index.html --shell-file html_template/index.html -s EXPORTED_RUNTIME_METHODS=ccall,cwrap -s EXPORTED_FUNCTIONS=_free,_malloc,_main,_processStr,_processArray,_processJson -s NO_EXIT_RUNTIME=1
    ```
  - cmake
    ```
    mkdir dist build
    cd build
    cmake ..
    make
    ```