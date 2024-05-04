/*
 * author: inkXu
 * date:   2022.8.2
 *
 * 重载&&和||操作
 *
 * 不介意重载这两个运算符，因为重载过后是先判断后面的操作，如：a && b，先判断b，再判断a，所以不建议对其重载
 * 也因为重载过后它的短路操作也不能得以实现了
 *
 * 符号重载小结：能用类的成员函数作重载就用成员函数，>> 和 << 用全局函数来重载，不要对&&和||重载
 */
#include<iostream>
using namespace std;

class myint
{
public:
  myint(int num)
  {
    this->num = num;
  }
  bool operator&&(myint& m)
  {
    return this->num && m.num;
  }
  myint &operator++()
  {
    (*this).num = (*this).num + 1;
    return *this;
  }
  int num;
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  myint b(0);
  bool flag = 0 && 1;
  cout << flag << endl;
  //下面运算是先对b++进行运算，结果为b=1，就成了 1 && 1 了
  flag = b && ++b;
  cout << flag << endl;
  
}







