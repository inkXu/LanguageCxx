/*
 * author: inkXu
 * date:   2022.8.4
 *
 * 通用排序
 *
 * 使用模板写一个通用排序函数
 * 当你的函数定义和声明分开来写时，定义和申明处都要加上模板template <class T>，T为模板名
 */
#include<iostream>
using namespace std;

void test1();
template <class T>
void sort(T *a, int n);
template <class T>
void print_num(T *a, int n);

int main()
{
  test1();
  return 0;
}

void test1()
{
  int num[] = { 388,9834,34,4746,1534,4575,7,2,34,6,645,745,436 };
  sort(num, sizeof(num)/sizeof(num[0]));
  print_num(num, sizeof(num)/sizeof(num[0]));

  cout << "*************************************************************" << endl;
  float float_num[] = { 98.4,457.2,645.56,23.76,75,24.76,998.34 };
  //这里在函数名后加了<>号，在其内可以直接告诉编译器模板T的类型是什么
  sort<float>(float_num, sizeof(float_num)/sizeof(float_num[0]));
  print_num<float>(float_num, sizeof(float_num)/sizeof(float_num[0]));
}
template <class T>
void print_num(T *a, int n)
{
  int i = 0;
  cout << a[i] << "   ";
  for(i = 1; i < n; i++)
  {
    if(i % 10 == 0)
      cout << endl;
    cout << a[i] << "   ";
  }
  cout << endl;
}
template <class T>
void sort(T *a, int n)
{
  for(int i = 0; i < n-1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      if(a[i] > a[j])
      {
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}







