/*
 * author: inkXu
 * date:   2022.8.4
 *
 * 类模板在头文件中声明
 */
#include<iostream>
#include<string>
#include"c_t_in_head_file.hpp"
using namespace std;

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Animal<string> animal("x100221");
  animal.show();
}







