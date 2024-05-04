/*
 * author: inkXu
 * date:   2022.8.10
 *
 * 有5名选手，选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取余下的平均分。
 * 1、创建五名选手，放到vecctor中
 * 2、遍历vector容器，取出每一个选手，执行for，可以把每一个评分存到deque中
 * 3、sort算法对deque容器中的分数排序，去除最高最低分
 * 4、算出平均分
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<stdlib.h>
using namespace std;

class Player
{
public:
  Player(string name, int score = 0)
  {
    this->name = name;
    this->score = score;
  }
  void setScore(int score)
  {
    this->score = score;
  }
  int getScore()
  {
    return this->score;
  }
  string getName()
  {
    return this->name;
  }
private:
  string name;
  int score;
};

void InitPlayer(vector<Player> &p, const string &ntemp);
void Score(vector<Player> &v);
void print(Player& player);

int main()
{
  string ntemp = "ABCDE";
  vector<Player> v_players;
  InitPlayer(v_players, ntemp);
  for_each(v_players.begin(), v_players.end(), print);
  Score(v_players);
  for_each(v_players.begin(), v_players.end(), print);

  return 0;
}

void print(Player& player)
{
  cout << player.getName() << "    " << player.getScore() << endl;
}

void Score(vector<Player> &v)
{
  deque<int> dScore;
  srand((unsigned int)time(NULL));

  for(vector<Player>::iterator it = v.begin(); it != v.end(); it++)
  {
    for(int i = 0; i < 10; i++)
    {
      dScore.push_back(60 + rand()%41);
    }

    //将分数放入vector容器中进行排序，减小资源损耗
    vector<int> v_temp;
    for(int i = 0; i < dScore.size(); i++)
    {
      v_temp.push_back(dScore[i]);
    }

    sort(v_temp.begin(), v_temp.end());

    dScore.clear();
    for(int i = 0; i< v_temp.size(); i++)
    {
      dScore.push_back(v_temp[i]);
    }

    dScore.pop_front();
    dScore.pop_back();

    int sum = 0;
    for(int i = 0; i < dScore.size(); i++)
    {
      sum += dScore.at(i);
    }
    (*it).setScore(sum / dScore.size());
    dScore.clear();
  }
}

void InitPlayer(vector<Player> &p, const string &ntemp)
{
  for(int i = 0; i < ntemp.size(); i++)
  {
    string name(1, ntemp[i]);
    Player player(name);
    p.push_back(player);
  }
}




