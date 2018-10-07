#include <iostream>
#include<stdio.h>
#include"student.h"
#include<vector>
#include<string>
#include<random>

//李楷 软件工程 2016051604109
using namespace std;

//抽奖名额设置

void SetAmount(int &a,int &b,int &c)
{
    cout<<"请设置一等奖，二等奖，三等奖的名额数目（默认各为1位）"<<endl;
    cin>>a>>b>>c;
}
//奖品设置
void SetFirst(string &firsts)
{
    while (true) {
    cout<<"一等奖奖品：1.computer 2.camera 3.air-condition 4.washer 5.其他______ (默认为computer)"<<endl<<"请设置："<<endl;
    string a="computer";
    string b="camera";
    string c="air-condition";
    string d="washer";
    int i;
    cin>>i;
    if(i==1){
        firsts=a;
        break;
    }
    else if (i==2) {
        firsts=b;
        break;
    }
    else if (i==3) {
       firsts=c;
       break;
    }
    else if (i==4) {
       firsts=d;
       break;
    }
    else if (i==5) {
        cout<<"请手动输入奖品：";
        string ss;
        cin>>ss;
        firsts=ss;
       break;
    }
    else {
       cout<<"输入有误，重新输入："<<endl;
    }
  }
}

void SetSecond(string &firsts)
{
    while (true) {


    cout<<"二等奖奖品：1.cellphone 2.2000 dollars 3.game machine 4.electrocar 5.其他______ (默认为electrocar)"<<endl<<"请设置："<<endl;
    string a="cellphone";
    string b="2000 dollars";
    string c="game machine";
    string d="electrocar";
    int i;
    cin>>i;
    if(i==1){
        firsts=a;
        break;
    }
    else if (i==2) {
        firsts=b;
        break;
    }
    else if (i==3) {
       firsts=c;
       break;
    }
    else if (i==4) {
       firsts=d;
       break;
    }
    else if (i==5) {
        cout<<"请手动输入奖品：";
        string ss;
        cin>>ss;
        firsts=ss;
       break;
    }
    else {
       cout<<"输入有误，重新输入："<<endl;
    }
  }
}

void SetThird(string &firsts)
{
    while (true) {


    cout<<"三等奖奖品：1.400 dollars 2.bicycle 3.1T hard disk 4.charger baby 5.其他______ (默认为600 dollars)"<<endl<<"请设置："<<endl;
    string a="600 dollars";
    string b="bicycle";
    string c="1T hard disk";
    string d="charge baby";
    int i;
    cin>>i;
    if(i==1){
        firsts=a;
        break;
    }
    else if (i==2) {
        firsts=b;
        break;
    }
    else if (i==3) {
       firsts=c;
       break;
    }
    else if (i==4) {
       firsts=d;
       break;
    }
    else if (i==5) {
       cout<<"请手动输入奖品：";
       string ss;
       cin>>ss;
       firsts=ss;
       break;
    }
    else {
       cout<<"输入有误，重新输入："<<endl;
    }
  }
}

