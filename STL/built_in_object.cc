/*
 * author: inkXu
 * date:   2022.8.10
 *
 * 内建函数对象
 *
 * 包含在头文件functional中，在/usr/include/c++/4.8.2/bits/stl_function.h文件中有定义
 * 就是前面算法需要的形参，那些仿函数，别人写好了，可以直接拿来用
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Print
{
public:
  void operator()(int num)
  {
    cout << num << endl;
  }
};

void test1();
void test2();

int main()
{
  test2();
  return 0;
}

void test2()
{
  //内建伪函数取反negate
  negate<int> p;
  cout << p(8) << endl;
  cout << negate<int>()(3) << endl;
}

void test1()
{
  vector<int> v;
  v.push_back(8);
  v.push_back(9);
  v.push_back(5);
  v.push_back(3);
  v.push_back(1);

  //从大到小排序
  sort(v.begin(), v.end(), greater<int>());
  //默认的算法头文件algorithm中，sort算法第三个参数默传入的内建函数是less<T>，从小到大排序
  sort(v.begin(), v.end(), less<int>());

  for_each(v.begin(), v.end(), Print());
}







