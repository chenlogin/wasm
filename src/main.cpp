#include <iostream>
#include <stdio.h>
#include <emscripten/emscripten.h>
#include <string> 
#include <sstream>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

// 使用 EMSCRIPTEN_KEEPALIVE 宏确保函数对JavaScript可见
// str 应该是一个有效的UTF-8字符串，可以直接传递给 printf 
EXTERN EMSCRIPTEN_KEEPALIVE void processStr(const char* str) {
  printf("strParam parameter = %s\n", str); 
}

//C风格的数组（一个指向数组第一个元素的指针和数组长度）
EXTERN EMSCRIPTEN_KEEPALIVE  void processArray(int* arr, size_t length) {  
  for (size_t i = 0; i < length; i++) {  
    arr[i] *= 2; // 示例：将数组中的每个元素乘以2
  } 
}

//WASM主要处理原始数据类型，它不直接支持JSON或其他高级数据结构
EXTERN EMSCRIPTEN_KEEPALIVE  const char* processJson(const char* data) {
  static std::string result; // 使用静态字符串以保留其值 
  // data是一个JSON格式的字符串，可以使用JSON解析库处理数据
  std::cout << data << std::endl;
  
  // 构建新的JSON字符串  
  result = "{\"a\":\"WASM\",\"b\":" + std::to_string(234) + ",\"c\": false" + "}";
  // 返回结果字符串的C风格字符串  
  return result.c_str();
}

// 递归方式计算斐波那契数列的第n个数
EXTERN EMSCRIPTEN_KEEPALIVE int fibonacci(int n, const char* str) {
  if (n <= 1){
    std::cout << str << std::endl;
    return n;
  } 
  return fibonacci(n - 1, str) + fibonacci(n - 2, str);
}

EXTERN EMSCRIPTEN_KEEPALIVE int add(int a, int b) {
  printf("a=%d,b=%d\n", a, b);
  std::cout << "a+b=" << a+b << std::endl;
  return a + b;
}

int main() {
    
    printf("Hello World\n");
    std::cout << "Hello WASM" << std::endl;
    
    // int n;
    // std::cin >> n;
    // std::cout << fibonacci(n);
    return 0;
}