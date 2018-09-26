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

void First(vector<Student *> student,int person,int j,string faward);//抽取一等奖
void FirstA(vector<Student *> &first,vector<Student *> student,string faward);

void Second(vector<Student *> student,int person,int j,string saward);//抽取二等奖
void SecondA(vector<Student *> &second,vector<Student *> student,string saward);

void Third(vector<Student *> student,int person,int j,string taward);//抽取三等奖
void ThirdA(vector<Student *> &third,vector<Student *> student,string taward);

void None(vector<Student *> &none,vector<Student *> student);//未中奖
void ResetSnum(vector<Student *> &student);//未中奖的人Snum置为0

void Printf(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *> none);//隐藏用户信息输出中奖历史



int main()
{


    vector<Student *> student;//参与者信息保存
    vector<Student *> first;//一等奖抽取
    vector<Student *> second;//二等奖抽取
    vector<Student *> third;//三等奖抽取
    vector<Student *>  none;//未中奖
    int a=1,b=1,c=1;


    string faward="computer";//一等奖默认奖品
    string saward="electrocar";//二等奖默认奖品
    string taward="600 dollars";//三等奖默认奖品

    //表格设计

    informations(student,person);
    First(student,person,a,faward);
    FirstA(first,student,faward);
    Second(student,person,b,saward);
    SecondA(second,student,saward);
    Third(student,person,c,taward);
    ThirdA(third,student,taward);
    None(none,student);
    Printf(first,second,third,none);
    cout<<"**抽奖结束，欢迎再次使用**"<<endl;
    return 0;
}

