/*
 * author: inkXu
 * date:   2022.8.3
 *
 * 使用多态实现计算器
 * 
 * 在实际开发中，源码是具有不可重写和可扩展性的，动态多态可以符合该要求
 */
#include<iostream>
using namespace std;

class Calculate
{
public:
  //定义个接口
  virtual float calc(float a, float b)
  {
    return 0;
  }
};
class Add: public Calculate
{
public:
  float calc(float a, float b)
  {
    return a + b;
  }
};
class Sub: public Calculate
{
public:
  float calc(float a, float b)
  {
    return a - b;
  }
};
class Mul: public Calculate
{
public:
  float calc(float a, float b)
  {
    return a * b;
  }
};

//定义个实现接口
float calculate(float a, float b, Calculate& cal)
{
  return cal.calc(a, b);
}

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Add add;
  cout << calculate(3.9, 3, add) << endl;
  Sub sub;
  cout << calculate(3.9, 3, sub) << endl;
  Mul mul;
  cout << calculate(3.9, 3, mul) << endl;
}







