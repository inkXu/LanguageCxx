/*
 * author: inkXu
 * date:   2022.8.10
 *
 * 函数对象
 *
 * 对()进行了重载的类叫做函数对象，也叫伪函数
 */
#include<iostream>
#include<algorithm>
using namespace std;

class MyAdd
{
public:
  int operator()(int a, int b)
  {
    return a + b;
  }
};
template <class T>
class Print
{
public:
  void operator()(T a)
  {
    cout << a << "   " ;
  }
};

void test1();
void test2();            //将函数对象传入for_each算法中

int main()
{
  test2();
  return 0;
}

void test2()
{
  int nums[] = { 2,6,3,4,65,34,2,345,98 };
  //第一二个参数传入指针，nums[0]不是指针，伪函数作为参数传入时要写成对象形式
  for_each(&nums[0], &nums[9], Print<int>());
  cout << endl;

  Print<int> p;
  //for_each算法中会调用括号，写个对象到这里就可以
  for_each(&nums[0], &nums[9], p);
  cout << endl;
}

void test1()
{
  MyAdd add;
  cout << add(3, 6) << endl;
  //通过匿名对象调用函数对象
  cout << MyAdd()(3, 6) << endl;
}







