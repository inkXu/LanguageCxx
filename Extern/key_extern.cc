/*
 * author: inkXu
 * date:   2022.7.24
 *
 * extern "C" 浅析
 *
 * C++编译器在编译时，会将函数名更改，在C++中写的函数名为另外的名字，
 * 而C还是原名，所以就会出现未识别的函数名的错误，所以要使用下面写法
 * 但是不知是我编译器的问题还是咋的，我的linux这么写没有用，我的vs能用
 */
#include <iostream>
extern "C"
{
#include "test.h"
}
using namespace std;

int main(int argc, char *argv[])
{
  int a = 100, b = 107;
  cout<< "myadd(a, b) = " << myadd(a, b) <<endl;
  return 0;
}






