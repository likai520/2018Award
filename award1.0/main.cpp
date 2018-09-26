#include <iostream>
#include<stdio.h>
#include"student.h"
#include<vector>
#include<string>
#include<random>

int person;//参与人数

//李楷 软件工程 2016051604109

using namespace std;


void cincout(int snum,vector<Student *> &student);//输入参与者信息
void informations(vector<Student *> &student,int &per);//输出参与者信息



int main()
{


    vector<Student *> student;//参与者信息保存

    informations(student,person);

    cout<<"**抽奖结束，欢迎再次使用**"<<endl;
    return 0;
}

