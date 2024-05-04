/*
 * author: inkXu
 * date:   2022.8.4
 *
 * 函数模板和普通函数的异同
 *
 * 函数模板不能自动进行类型转换，普通函数可以
 * 函数模板可以个普通函数进行重载
 * 进行重载后，编译器会自行选择使用哪个，原则如下test1
 */
#include<iostream>
using namespace std;

int Add(int a, int b);
template <class T>
T Add(T &a, T &b);
void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  int a = 10;
  int b = 10;
  char c = 'a';
  char d = 'd';
  cout << "int a, b;  char c, d;" << endl;
  //下面操作默认使用普通函数，因为模板函数还需要进行判断操作
  cout << "Add(a,b) = " << Add(a, b) << endl;
  //若一定要用模板函数，可以加<> 或 <type>
  cout << "Add<>(a,b) = " << Add<>(a, b) << endl;
  cout << "Add<int>(a,b) = " << Add<int>(a, b) << endl;
  //下面使用的是普通函数，普通函数可以从char类型转为int类型，因为a和c为不同类型
  cout << "Add(a,c) = " << Add(a, c) << endl;
  //报错，模板函数不能进行类型转换
  //cout << Add<>(a, c) << endl;
  //使用的是模板函数，因普通函数需要进行类型转换，而模板判断类型后就可以直接使用，就是运行结果有问题
  cout << "Add(c, d) = " << Add(c, d) << endl;
}
template <class T>
T Add(T &a, T &b)
{
  cout << "template function is used" << endl;
  return a + b;
}
int Add(int a, int b)
{
  cout << "common function is used" << endl;
  return a + b;
}







