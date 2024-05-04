/*
 * author: inkXu
 * date:   2022.8.11
 *
 * 函数对象适配器
 *
 * 用来适配参数，扩展函数接口，一般结合仿函数一起使用
 * 适配器的使用，第一步将需要适配的仿函数继承一元函数类模板(unary_function)或二元函数类模板(binary_function)，
 * 第二步，成员函数operator()的this指针需要加上const修饰，
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Print: public binary_function<int, int, void>
{
public:
  void operator()(int a, int b) const
  {
    cout << a << "   " << b << endl;
    cout << a + b << endl;
  }
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  vector<int> v;
  v.push_back(8);
  v.push_back(5);
  v.push_back(0);
  v.push_back(9);

  //这里的第三个参数为一个匿名对象，但是Print类对operator()重载后需要两个参数，所以需要使用适配器
  //for_each(v.begin(), v.end(), Print());
  //有两种方式，bind1st和bind2nd，第一种在传入参数时，bind1st中第二个实参会传给operator()的第一个形参位置，
  //而通过for_each遍历的值会传给operator()的第二个形参位置，而bind2nd则相反，第二个常用；
  for_each(v.begin(), v.end(), bind1st(Print(), 400));

  for_each(v.begin(), v.end(), bind2nd(Print(), 300));
}







