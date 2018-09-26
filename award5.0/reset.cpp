#include <iostream>
#include<stdio.h>
#include"student.h"
#include<vector>
#include<string>
#include<random>

//李楷 软件工程 2016051604109
using namespace std;

void reset(vector<Student *> &student)
{
//    cout<<"重置抽奖状态，还原为抽奖时的状态。"<<endl;
    for(auto &g:student){
        if(g->getSnum()!=g->getAnum()){
            g->setSnum(g->getAnum());
        }
    }

}
//抽奖完成后自动清空用户信息
void clear(vector<Student *> &student)
{
    student.clear();
}
