/*
 * author: inkXu
 * date:   2022.8.10
 *
 * 谓词
 *
 * 返回值类型为bool类型的普通函数，或是重载了operator()，且它的返回值为bool类型的类，若是形参个数为一个，
 * 则为一元谓词，有两个则为二元谓词，谓词可作为判断式
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Compare
{
public:
  //一元谓词，比8大
  bool operator()(int num)
  {
    return num > 8;
  }
};
class _Compare
{
public:
  //二元谓词
  bool operator()(const int num1, const int num2)
  {
    return num1 > num2;
  }
};
class Print
{
public:
  void operator()(int a)
  {
    cout << a << endl;
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
  vector<int> v;
  v.push_back(8);
  v.push_back(4);
  v.push_back(10);
  v.push_back(18);
  v.push_back(1);

  sort(v.begin(), v.end(), _Compare());
  for_each(v.begin(), v.end(), Print());
}

void test1()
{
  vector<int> v;
  v.push_back(8);
  v.push_back(4);
  v.push_back(10);
  v.push_back(18);
  v.push_back(1);

  //第三个参数为谓词，该函数返回值为迭代器
  cout << *(find_if(v.begin(), v.end(), Compare())) << endl;
}







