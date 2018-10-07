#include <iostream>
#include<stdio.h>
#include"student.h"
#include<vector>
#include<string>
#include <fstream>

//李楷 软件工程 2016051604109
//张黎明 软件工程 2016051604105
using namespace std;

//输入信息
int getLength(int i);
void cincout(int snum,vector<Student *> &student)
{
    Student *p;
    snum=1;//抽奖号第一位为1,随后递增
    int anum;
    ofstream mycout("../2018Award/data.txt",ios::app);
    while (true) {
        string name;
        string sex;
        int num;//学号
        int classes;//班级
        string information;//专业信息
        string award="thank you";//未抽奖前所有人的奖品设置为谢谢回顾

        cout<<"please enter student's name,sex,number,class,major"<<endl;
        cin>>name>>sex>>num>>classes>>information;

        if(num<0||classes<0){
            //保证输入的学号和班级为整型
            cout<<"student's number or class is invalid,please enter again."<<endl;
            cout<<"please enter 学号 and 班级:"<<endl;
            cin>>num>>classes;
        }

        anum=snum;
        p=new Student(name,sex,num,classes,snum,anum,information,award);
        mycout << name << ' ' << sex << ' ' << num << ' ' << classes << ' ' << information << endl;
        snum++;
        student.push_back(p);

        int i;
        cout<<"结束输入按 1,继续按任意键"<<endl;
        cin>>i;
        if(i==1)break;
    }
    mycout.close();
}
void infile(int snum,vector<Student *> &student)
{
    Student *p;
    snum=1;//抽奖号第一位为1,随后递增
    int anum;
    ifstream mycin;
    string name;
    string sex;
    int num;//学号
    int classes;//班级
    string information;//专业信息
    string award="thank you";//未抽奖前所有人的奖品设置为谢谢回顾
    mycin.open("../2018Award/data.txt");
    if(!mycin) cout << "error" << endl;
    while (mycin) {
        mycin>>name>>sex>>num>>classes>>information;
        if(mycin){
            anum=snum;
            p=new Student(name,sex,num,classes,snum,anum,information,award);
            snum++;
            student.push_back(p);
        }
    }
}
//输出信息
void informations(vector<Student *> &student,int &per)
{

    int snum=0;
    int i=0;
    per=0;//计算人数

    cout << "Please enter 1(文件输入) or 2(手动输入)" << endl;
    cin >> i;
    if(i == 1)
        infile(snum,student);
    else if(i == 2)
        cincout(snum,student);
    else{
        cout << "ERROR:Please enter again." << endl;
        return;
    }

    //                    14      7        10        10        10         11
    string ss="name          sex    class     num       major     awardNumber";
    string firsts(ss.size()+2,'-');
    cout<<"参与者信息："<<endl;
    cout<<firsts<<endl;
    cout<<"|"<<ss<<"|"<<endl;
    //输出所有用户信息
    for(auto &l:student){
        per++;
        string names(13-l->name().size(),' ');
        string sexs(7-l->getSex().size(),' ');
        string classes(10-getLength(l->getClass()),' ');
        string nums(10-getLength(l->getNum()),' ');
        string majorss(10-l->getInformation().size(),' ');
        string awards(11-getLength(l->getSnum()),' ');

        cout<<"| "<<l->name()<<names
           <<l->getSex()<<sexs
          <<l->getClass()<<classes
         <<l->getNum()<<nums
        <<l->getInformation()<<majorss
        <<l->getSnum()<<awards
        <<"|"<<endl;
    }
    cout<<firsts<<endl<<endl;
}

//计算整型的长度
int getLength(int i)
{
    int len=1;
    for(;i/10>0;i/=10)
    {
        len++;
    }
    return len;
}
