/*
 * author: inkXu
 * date:   2022.8.6
 *
 * vector容器
 *
 * vector的内部存储结构类似array，若是vector的容量达到上限，它会自动申请内存，而后将原来的数据拷贝到新申请的
 * 内存中，每次申请的内存大小是原来容量的两倍
 * 
 * 注意，注意，注意
 *   若是你新建了个迭代器，它指向一个容器，在使用过程中，你的容器容量不够了，它会开辟了新的内存，
 *   这时，你原来的迭代器是不能使用了的，它指向的是已经释放了的空间
 */
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<algorithm>
using namespace std;

class Animal
{
public:
  Animal(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
  string name;
  int age;
};
void test1();
void test2();    //每次扩容大小问题
void test3();
void test4();    //赋值操作
void test5();    //大小操作
void test6();    //存取操作
void test7();    //插入和删除
void test8();    //巧用swap缩容        感觉挺重要的
void test9();    //计算vector容器新开辟内存的次数
void test10();   //vector容器的排序，vector容器中没有排序的算法，但是有通用的算法函数
void test11();   //对对象排序，一种是写operator<，调用sort默认的从小到大排序法，或是直接写一个比较对象的函数传入
void print(int a)
{
  cout << a << "  ";
}
void print_Animal(Animal &animal)
{
  cout << animal.name << " " << animal.age << "         ";
}
bool campare(int a, int b)
{
  return a > b;
}
bool campare_Animal(const Animal &a, const Animal &b)
{
  //不知道sort算法内部的工作原理，sort好像会调用多次该函数
  return a.age > b.age;  //a.name.compare(b.name) > 0 && 
}

int main()
{
  test9();
  return 0;
}

void test11()
{
  vector<Animal> v;

  v.push_back(Animal("miki", 23));
  v.push_back(Animal("sani", 21));
  v.push_back(Animal("raki", 13));
  v.push_back(Animal("aaki", 33));

  for_each(v.begin(), v.end(), print_Animal);
  cout << endl;

  sort(v.begin(), v.end(), campare_Animal);

  for_each(v.begin(), v.end(), print_Animal);
  cout << endl;
}

void test10()
{
  vector<int> v;

  v.push_back(8);
  v.push_back(73);
  v.push_back(19);
  v.push_back(34);

  for_each(v.begin(), v.end(), print);
  cout << endl;

  //默认排序，从小到大
  sort(v.begin(), v.end());

  for_each(v.begin(), v.end(), print);
  cout << endl;

#if 0
  //从大到小排序，方法一
  sort(v.rbegin(), v.rend());

  for_each(v.begin(), v.end(), print);
  cout << endl;
#endif

  //从大到小排序，方法二，第三个参数传入函数指针，参数类型为template <class T> bool (*)(T t1, T t2)
  sort(v.begin(), v.end(), campare);

  for_each(v.begin(), v.end(), print);
  cout << endl;
}

void test9()
{
  vector<int> v;
  int *p = NULL;
  int count = 0;

  for(int i = 0; i < 10000; i++)
  {
    v.push_back(i);
    //v[0]是一个引用，是一个值，不是地址
    if(p != &v[0])
    {
      count++;
      p = &v[0];
    }
  }
  cout << "count = " << count << endl;
}

void test8()
{
  vector<int> v;

  for(int i = 0; i < 10000; i++)
  {
    v.push_back(i);
  }

  cout << "v.size() = " << v.size() << endl;
  cout << "v.capacity() = " << v.capacity() << endl;

  v.resize(50);    //50后面的数据都不要，这时，容器容量仍然是原来的容量，造成了空间浪费

  cout << "v.size() = " << v.size() << endl;
  cout << "v.capacity() = " << v.capacity() << endl;

  //隐式调用了拷贝构造，将容器v拷贝给新容器，隐式创建的对象再调用swap函数，将v指向的地址和隐式对象的地址互换
  //拷贝构造应该是只拷贝值，没有拷贝容量大小，容量设置为拷贝的内容大小
  vector<int>(v).swap(v);

  cout << "v.size() = " << v.size() << endl;
  cout << "v.capacity() = " << v.capacity() << endl;
}

/*
 * 插入和删除
 * insert(const_iterator pos, int count, elem);     //在迭代器pos指向的位置插入count个elem
 * push_back(elem);                                 //尾插法
 * pop_back();                                      //删除最后一个元素
 * erase(const_iterator start, const_iterator end); //删除迭代器从start到end的元素
 * erase(const_iterator pos);                       //删除迭代器指向的元素
 * clear();                                         //清楚容器中所有元素
 */
void test7()
{
  vector<int> v;

  for(int i = 0; i < 23; i = i + 3)
  {
    v.push_back(i);
  }

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.insert(v.begin() + 3, 3, 888);

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.pop_back();

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.erase(v.begin() + 2, v.begin() + 4);   //第二个参数所指的值不删

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.erase(v.begin() + 2, v.end());   //第二个参数所指的值不删
  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.erase(v.begin());

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.clear();

  cout << "v.empty() = " << v.empty() << endl;
}

/*
 * 存取操作
 * at(int index);    //越界直接抛出out_of_range异常
 * operator[];       //越界时直接报错，过大会段错误，不是特别大值可能是0
 * front();          //若没有程序运行时直接段错误
 * back();           //若没有程序运行时直接段错误
 */
void test6()
{
  vector<int> v;

  try
  {
    //cout << "v.front()" << v.front() << endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "v.front() = " << v.front() << endl;
    cout << "v.back() = " << v.back() << endl;

    cout << "v.at(2) = " << v.at(2) << endl;
    cout << "v[1] = " << v[1] << endl;
  }
  catch(exception &e){
    cout << "error:" << e.what() << endl;
  }
}

/*
 * 大小操作
 * size();
 * empty();                 //判断容器是否为空
 * resize(int num);         //重新指定容器的长度为num，若容器变长了，则使用默认值填充新位置，变短删除超出的位置
 * resize(int num, elem);   //重新指定容器的长度为num，若容器变长了，则使用elem填充新位置，变短删除超出的位置
 * capacity();              //返回容量大小
 * reserve(int len);        //容器预留len个元素长度，预留位置不初始化，元素不可访问，预先设定容量
 */
void test5()
{
  vector<int> v;
  vector<int> v1;

  for(int i = 0; i < 23; i = i + 3)
  {
    v.push_back(i);
  }

  cout << "v.size() = " << v.size() << endl;
  cout << "v.empty() = " << v.empty() << endl;
  cout << "v1.empty() = " << v1.empty() << endl;
  v.resize(9);
  for_each(v.begin(), v.end(), print);
  cout << endl;
  v.resize(13, 888);
  for_each(v.begin(), v.end(), print);
  cout << endl;
  cout << "v.capacity() = " << v.capacity() << endl;

  v1.reserve(1000);
  cout << "v1.size() = " << v1.size() << endl;
  cout << "v1.capacity() = " << v1.capacity() << endl;
}

/*
 * 赋值操作
 *
 * assign(beg, end);                         //将beg到end区间的元素拷贝给自身
 * assign(n, elem);                          //将n个ele拷贝给自身
 * vector& operator=(const vector& vec);     //重载等号
 * swap(vec);                                //将vec与本身的元素互换，该交换原理是将指针的指向交换一下，效率
 */
void test4()
{
  vector<int> v;

  for(int i = 0; i < 99; i = i + 13)
  {
    v.push_back(i);
  }

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.assign(v.begin() + 2, v.end());

  for_each(v.begin(), v.end(), print);
  cout << endl;

  v.assign(7, 3);

  for_each(v.begin(), v.end(), print);
  cout << endl;

  vector<int> v1 = v;
  v1.push_back(9999);

  for_each(v1.begin(), v1.end(), print);
  cout << endl;

  v.swap(v1);

  for_each(v.begin(), v.end(), print);
  cout << endl;
  for_each(v1.begin(), v1.end(), print);
  cout << endl;
}

/*
 * vector构造函数
 *
 * vector<T>();
 * vector(v.begin(), v,end());
 * vector(n, elem);                    //将n个elem拷贝给自身
 * vector(const vector &vec);          //拷贝构造
 */
void test3()
{
  vector<int> v;

  for(int i = 5; i < 23; i = i + 4)
  {
    v.push_back(i);
  }
  for_each(v.begin(), v.end(), print);
  cout << endl;

  vector<int> v1(v);
  for_each(v1.begin(), v1.end(), print);
  cout << endl;

  //vector<int> v(array, array + sizeof(array)/sizeof(array[0]))
  vector<int> v2(v1.begin() + 2, v1.end());
  for_each(v2.rbegin(), v2.rend(), print);
  cout << endl;
}
void test2()
{
  vector<int> v;

  for(int i = 0; i < 100; i++)
  {
    v.push_back(i);
    cout << "capacity is " << v.capacity() << endl;
  }
}

/*
 * vector的迭代器
 *
 *                                                                               push_back  -------------+
 *    +----------------------------------------------------------------------------------------------+   |
 *    |           |    1    |    2    |    3    |    4    |    5    |    6    |    7    |            | <-+
 *    |           |         |         |         |         |         |         |         |            | --+
 *    +----------------------------------------------------------------------------------------------+   |
 *                                                                               pop_back  <-------------+
 *
 *      rend          begin                                                     rbegin        end
 * reverse_iterator  iterator                                            reverse_inerator    interator
 */
void test1()
{
  vector<int> v;

  for(int i = 1; i < 8; i++)
  {
    v.push_back(i);
  }

  vector<int>::iterator start = v.begin();
  vector<int>::iterator end = v.end();

  for( ; start != end; start++)
  {
    cout << *start << "   ";
  }
  cout << endl;

  vector<int>::reverse_iterator rstart = v.rbegin();
  vector<int>::reverse_iterator rend = v.rend();

  for( ; rstart != rend; rstart++)
  {
    cout << *rstart << "   ";
  }
  cout << endl;
}







