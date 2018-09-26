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

void Printf(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *>  none);//输出中奖历史
void PrintfNO(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *> none);//隐藏用户信息输出中奖历史
void SetAmount(int &a,int &b,int &c);//设置中奖名额

void SetFirst(string &firsts);//各个奖品的设置
void SetSecond(string &firsts);
void SetThird(string &firsts);
void reset(vector<Student *> &student);//重置
void clear(vector<Student *> &student);//用户信息清空


int main()
{


    vector<Student *> student;//参与者信息保存
    vector<Student *> first;//一等奖抽取
    vector<Student *> second;//二等奖抽取
    vector<Student *> third;//三等奖抽取
    vector<Student *>  none;//未中奖
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
            cout<<"--参与人数："<<person<<endl;
            while (true) {
                cout<<"--1.进行抽奖(可重置重新抽奖)"<<endl
                    <<"--2.保存（保存之后无法再次重新抽奖)"<<endl
                    <<"--3.返回"<<endl;
                cout<<"--选择：";
                int i;
            cin>>i;
            if(i==1){
            reset(student);
            First(student,person,a,faward);
            Second(student,person,b,saward);
            Third(student,person,c,taward);
            cout<<"----抽奖完成..... "<<endl<<endl;

            }
            else if (i==2) {
                FirstA(first,student,faward);
                SecondA(second,student,saward);
                ThirdA(third,student,taward);
                ResetSnum(student);
                None(none,student);
                cout<<"----保存成功....."<<endl<<endl;
                clear(student);
            }
            else if(i==3){
               printf("----------萌----------新-----------限-----------定-----------分-----------割-----------线---------\n");
               cout<<endl;
                           break;
             }
            else {
                cout<<"输入有误，重新输入："<<endl;
             }
            }
            break;
        case 3:          
            //显示格式，查询，删除，恢复功能未实现
            while (true) {
                cout<<endl;
            cout<<"--1.历史中奖记录"<<endl
                <<"--2.查询"<<endl//未实现
                <<"--3.删除"<<endl//未实现
                <<"--4.返回"<<endl;
            cout<<"--选择：";
            int is;
            cin>>is;
            if(is==1){
                cout<<"--历史中奖用户和参与用户--"<<endl;
                if(d==1)
                    Printf(first,second,third,none);
                if(d==2)
                    PrintfNO(first,second,third,none);
                printf("----------萌----------新-----------限-----------定-----------分-----------割-----------线---------\n");
                cout<<endl;
              }
//            else if (is==2) {
//               //未实现
//              }
//            else if (is==3) {
//               //未实现
//              }
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
                    <<"--4.输出格式设置"<<endl//未实现
                    <<"--5.返回          "<<endl;
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
//                else if(i==4){
                    //未实现
//                }
                else if (i==5) {
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

