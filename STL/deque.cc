/*
 * author: inkXu
 * date:   2022.8.6
 *
 * deque 容器
 *
 * 应该和链表差不多的东西，插入、删除等方便，但排序耗内存，建议先将deque赋值给vector，排序完赋值回deque
 *
 *   +------ push_front                                                      push_back -----+
 *   |    +-----------------------------------------------------------------------------+   |
 *   +->  |     |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  1  |  1  |     | <-+
 *   +--  |     |     |     |     |     |     |     |     |     |     |     |     |     | --+
 *   |    +-----------------------------------------------------------------------------+   |
 *   +-----> pop_front                                                       pop_back  <----+
 *              begin                                                                end
 */
#include<iostream>
using namespace std;

void test1();

int main()
{
  test1();
  return 0;
}

/*
 * deque构造函数
 * deque<T> deqT;
 * deque(beg, end);
 * deque(n, elem);
 * deque(const deque &deq);
 */
void test1()
{
}

/*
 * deque赋值操作
 * assign(beg, end);
 * assign(n, elem);
 * deque& operator=(const deque &deq);
 * swap(deq);
 */
void test2()
{
}

/*
 * deque大小操作
 * deque.size();
 * deque.empty();
 * deque.resize(num);             //个数改为num，改后多了就删除多的，少了就补0
 * deque.resize(num, elem);       //个数改为num，改后多了就删除多的，少了就补elem
 */
void test3()
{
}

/*
 * deque双端插入删除操作
 * push_back(elem);
 * push_front(elem);
 * pop_back();
 * pop_front();
 */
void test4()
{
}

/*
 * deque数据存取
 * at(idx);
 * operator[];
 * front();             //第一个元素
 * back();              //最后一个元素
 */
void test5()
{
}

/*
 * deque插入操作
 * insert(pos, elem);
 * insert(pos, n, elem);
 * insert(pos, begin, end);     //在调用该函数的容器的pos位置插入一个容器的begin到end区间的数据，无返回值
 */
void test6()
{
}

/*
 * deque删除操作
 * clear();
 * erase(beg, end);   //返回值为下个数据的位置
 * erase(pos);        //返回值为下个数据的位置
 */
void test7()
{
}






