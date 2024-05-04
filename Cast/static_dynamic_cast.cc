/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 静态转换
 *
 * 本质上就是个模板static_cast<要转换的类型>(要转换的对象)
 */
#include<iostream>
using namespace std;

class A;
class B;
void test1();
void test2();

int main()
{
  test2();
  return 0;
}

class A
{
public:
};
class B: public A
{
public:
};
void test3()
{
#if 0
  //不能做内置类型的指针的强制转换
  int a = 100;
  int *pi = &a;
  double *pd = dynamic_cast<double *>(pi);
  cout << *pd << endl;
#endif

  A *pa = new A;
  B *pb = new B;
  //动态转换不能进行内置类型的转换
  double b = 3.1415;
  //int a = dynamic_cast<int>(b);

  //动态的比静态的感觉就是多了个编译检测，不会像静态的一样漏了，结果在运行的时候程序崩溃
  pa = dynamic_cast<A *>(pb);          //子转父
  //pb = dynamic_cast<B *>(pa);        //父转子
  delete pa;
  delete pb;
}
void test2()
{
  A *pa = new A;
  B *pb = new B;
  //当两个类发生继承时，可以进行强制转换，子类强转为父类时是安全的，不会发生内存泄漏
  pb = static_cast<B *>(pa);
  //父类转换成子类时是不安全的，子类的访问的变量多，父类访问的变量少，父类转换为子类后，它就是子类类型的变量，
  //能调用子类的参数，而父类没有这个参数，就会发生内存泄漏
  pa = static_cast<A *>(pb);
  delete pa;
  delete pb;
}
void test1()
{
  int a = 100;
  double b = 3.14159265359;
  char c = 'a';
  //static_cast 能用来转换系统的内置类型，如int、float之类的
  cout << "a = " << a << endl;
  a = static_cast<int>(c);
  cout << "a = " << a << endl;

  a = static_cast<int>(b);
  cout << "a = " << a << endl;

  a = 100;
  cout << "c = " << c << endl;
  c = static_cast<char>(a);
  cout << "c = " << c << endl;

#if 0
  //不能做普通内置类型的指针的强制转换
  int *pa = &a;
  double *pb = static_cast<double *>(pa);
  cout << *pb << endl;
#endif
}







