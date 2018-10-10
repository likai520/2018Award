#include <iostream>
#include<stdio.h>
#include"student.h"
#include<vector>
#include<string>
#include<random>
#include<iterator>

int person;//参与人数

//李楷 软件工程 2016051604109
//王佳

using namespace std;


void cincout(int snum,vector<Student *> &student);//输入参与者信息
void informations(vector<Student *> &student,int &per);//输出参与者信息

void First(vector<Student *> student,int person,int j,string faward,vector<Student *> &first);//抽取一等奖

void Second(vector<Student *> student,int person,int j,string saward,vector<Student *> &second);//抽取二等奖

void Third(vector<Student *> student,int person,int j,string taward,vector<Student *> &third);//抽取三等奖

void ResetSnum(vector<Student *> &student);//未中奖的人Snum置为0

void Printf(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *>  student);//输出中奖历史
void PrintfNO(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *> student);//隐藏用户信息输出中奖历史
void SetAmount(int &a,int &b,int &c);//设置中奖名额

void SetFirst(string &firsts);//各个奖品的设置
void SetSecond(string &firsts);
void SetThird(string &firsts);

void clear(vector<Student *> &student);//用户信息清空
int getLength(int i);


int main()
{


    vector<Student *> student;//参与者信息保存
    vector<Student *> first;//一等奖抽取
    vector<Student *> second;//二等奖抽取
    vector<Student *> third;//三等奖抽取
//    vector<Student *>  none;//未中奖
    int a=1,b=1,c=1;//设置抽奖各个等级的人数，默认为1
    int d=1;//设置用户信息是否显示输出，默认1为显示输出,0只输出奖号;
    int choose;

    string faward="computer";//一等奖默认奖品
    string saward="electrocar";//二等奖默认奖品
    string taward="600 dollars";//三等奖默认奖品

    //表格设计
    string s1="1.输入参与者信息";
    string firsts(s1.size()+2,'-');
    string s2="2.开始抽奖";
    string s3="3.抽奖功能";
    string s4="4.设置";
    string s5="5.退出";

    string f1(7,' ');
    string f2(s1.size()-s2.size()+4,' ');
    string f3(s1.size()-s3.size()+4,' ');
    string f4(s1.size()-s4.size()+2,' ');
    string f5(s1.size()-s5.size()+2,' ');

    //界面设计
    while (true) {

        cout<<firsts<<endl;
        cout<<"|"<<s1<<f1<<"|"<<endl
           <<"|"<<s2<<f2<<"|"<<endl
          <<"|"<<s3<<f3<<"|"<<endl
         <<"|"<<s4<<f4<<"|"<<endl
        <<"|"<<s5<<f5<<"|"<<endl;
        cout<<firsts<<endl;
        cout<<"--功能选择：";
        cin>>choose;
        cout<<endl;
        switch (choose) {
        case 1:
            informations(student,person);
            cout<<"--参与人数："<<person<<endl<<endl;
            printf("----------萌----------新-----------限-----------定-----------分-----------割-----------线---------\n");
            cout<<endl;
            break;
        case 2:
            if(student.size()==0){
                cout<<"----无法进行，请重新输入参与者信息！----"<<endl;
            }
            cout<<"--参与人数："<<person<<endl;

            First(student,person,a,faward,first);
            Second(student,person,b,saward,second);
            Third(student,person,c,taward,third);
            ResetSnum(student);


            break;
        case 3:
            //显示格式，查询，删除，恢复功能未实现
            while (true) {
                cout<<endl;
                cout<<"--1.历史中奖记录"<<endl
                   <<"--2.查询"<<endl
                  <<"--3.删除"<<endl
                 <<"--4.返回"<<endl;
                cout<<"--选择：";
                int is;
                cin>>is;
                if(is==1){
                    cout<<"--历史中奖用户和参与用户--"<<endl;
                    if(d==1)
                        Printf(first,second,third,student);
                    if(d==2)
                        PrintfNO(first,second,third,student);
                    printf("----------萌----------新-----------限-----------定-----------分-----------割-----------线---------\n");
                    cout<<endl;
                }
                else if (is==2){
                    cout<<""
                          ""
                          ""
                          ""
                          "1.根据名字查询\n2.根据性别查询\n3.根据学号查询\n4.抽奖号查询\n5.根据班级查询\n6.根据专业查询\n"<<endl;
                    cout<<"--选择：" ;
                    cin >> is;
                    if(is==1){

                        cout<<"-请输入名字："<<endl;
                        string name;
                        cin >> name;
                        for(auto &l:student){
                            if(name==l->name()){
                                l->printinformation();
                            cout<<"-------"<<endl;
                            }
                        }

                    }
                    if(is==2){
                        cout<< "1.女\n2.男"<<endl;
                        int a;
                        cin>>a;
                        if(a==1){
                            for(auto &l:student){
                                if(l->getSex()=="girl"){
                                l->printinformation();
                                cout<<"-------"<<endl;
                                }
                            }
                        }
                        if(a==2){
                            for(auto &l:student){
                                if(l->getSex()=="boy"){
                                    l->printinformation();
                                cout<<"-------"<<endl;
                                }
                            }
                        }
                    }
                    if(is==3){
                        cout<<"-请输入学号："<<endl;
                        cin>>a;
                        for(auto &l:student){
                            if(l->getNum()==a){
                                l->printinformation();
                            cout<<"-------"<<endl;
                            }
                        }
                    }
                    if(is==4){
                        cout<<"-请输入抽奖号: "<<endl;
                        cin>>a;
                        for(auto &l:student){
                            if(l->getSnum()==a){
                                l->printinformation();
                            cout<<"-------"<<endl;

                            }

                        }
                    }
                    if(is==5){
                        cout<<"-请输入班级"<<endl;
                        cin>>a;
                        for(auto &l:student){
                            if(l->getClass()==a){
                                l->printinformation();
                                cout<<"-------"<<endl;
                            }
                        }
                    }
                    if(is==6){
                        cout<<"-请输入专业："<<endl;
                        string major;
                        cin>>major;
                        for(auto &l:student){
                            if(l->getInformation()==major){
                                l->printinformation();
                            cout<<"-------"<<endl;
                            }
                        }
                    }
                }
                else if (is==3) {
                    cout<<"-请输入你将删除的学生学号："<<endl;
                    int b;
                    cin>>b;
                    for(auto &l:student){
                        if(l->getNum()==b)
                            l->setSnum(-4);
                    }
                    cout<<"----删除成功。"<<endl<<endl;
                    Printf(first,second,third,student);
                }
                else if(is==4){
                    printf("----------萌----------新-----------限-----------定-----------分-----------割-----------线---------\n");
                    cout<<endl;
                    break;
                }
                else{
                    cout<<"--输入有误，重新输入："<<endl;
                }
            }
            break;
        case 4:
            while (true) {
                cout<<"--1.设置中奖名额数目"<<endl
                   <<"--2.设置奖品种类   "<<endl
                  <<"--3.用户信息的保密性"<<endl
                <<"--4.返回          "<<endl;
                cout<<"--选择：";
                int i;
                cin>>i;
                if(i==1){
                    SetAmount(a,b,c);
                    printf("----------新----------娘-----------限-----------定-----------分-----------割-----------线---------\n");
                    cout<<endl;

                }
                else if (i==2) {
                    cout<<"**注意：手动输入时，有多个单词的请用-连接**"<<endl;
                    SetFirst(faward);
                    SetSecond(saward);
                    SetThird(taward);
                }
                else if (i==3) {
                    cout<<endl;
                    cout<<"--1.公开用户信息--"<<endl
                       <<"--2.隐藏用户信息--"<<endl
                      <<"--请设置：";
                    int j;
                    cin>>j;
                    if(j==1)
                        d=1;
                    else if (j==2) {
                        d=2;
                    }
                    else {
                        cout<<"--输入有误，重新输入："<<endl;
                    }
                    if(d==1||d==2)
                        cout<<"--设置成功--"<<endl<<endl;

                }
                else if (i==4) {
                    printf("----------萌----------新-----------限-----------定-----------分-----------割-----------线---------\n");
                    cout<<endl;
                    break;
                }
                else {
                    cout<<"--输入有误，重新输入："<<endl;
                }

            }
            break;
        case 5:
            break;
        default:
            cout<<"--输入错误，请正确输入:"<<endl;
            break;
        }
        if(choose ==5)break;
    }
    cout<<"**抽奖结束，欢迎再次使用**"<<endl;
    return 0;
}

