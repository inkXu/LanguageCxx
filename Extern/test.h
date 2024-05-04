//防止头文件重复包含的预处理命令
#pragma once

//C语言的头文件不支持下面注释的用法，所以需要在编写C++时给包含的头文件使用下面的写法
//这样才可以在C++中使用C语言编写的库
/*
//如果是C++编译器，就加上extern "C"的意思
#ifdef __cplusplus
#if __cplusplus
  extern "C" {
#endif
#endif
*/

int myadd(int a, int b);

/*
#ifdef __cplusplus
#if __cplusplus
  }
#endif
#endif
*/
