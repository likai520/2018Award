#include <iostream>
#include<stdio.h>
#include"student.h"
#include<vector>
#include<string>
#include<random>

//李楷 软件工程 2016051604109
using namespace std;
int getLengths(int i);

//抽一等奖的幸运户
void First(vector<Student *> student,int person,int a,string faward,vector<Student *> &first)
{
    int random;
    random=rand()%person+1;
    int i=0;
    while (i<a) {
    for(auto &l:student){
        if(l->getSnum()==random){
            i++;
            cout<<"恭喜--"<<l->name()<<"--的用户得到一等奖--"<<faward<<"--的大礼包"<<endl;
            l->setSnum(-1);
            l->setAward(faward);
            first.push_back(l);
        }
    }
    }
    cout<<"抽一等奖的幸运户完成...."<<endl<<endl;

}



//抽二等奖的幸运户

void Second(vector<Student *> student,int person,int b,string saward,vector<Student *> &second)
{
    int i=0;
    int random;
    while (i<b) {
        random=rand()%person+1;
        for(auto &l:student){
            if(l->getSnum()==random){
                i++;
                cout<<"恭喜--"<<l->name()<<"--的用户得到二等奖--"<<saward<<"--的大礼包"<<endl;
                l->setSnum(-2);
                l->setAward(saward);
                second.push_back(l);
            }
        }
    }
    cout<<"抽二等奖的幸运户完成...."<<endl<<endl;
}


//抽三等奖的幸运户
void Third(vector<Student *> student,int person,int c,string taward,vector<Student *> &third)
{
    int i=0;
    int random;
    while (i<c) {
        random=rand()%person+1;
        for(auto &l:student){
            if(l->getSnum()==random){
                i++;
                cout<<"恭喜--"<<l->name()<<"--的用户得到三等奖--"<<taward<<"--的大礼包"<<endl;
                l->setSnum(-3);
                l->setAward(taward);
                third.push_back(l);
            }
        }
    }
    cout<<"抽三等奖的幸运户完成...."<<endl<<endl;
}



//未中奖的人的抽奖号重置为0
void ResetSnum(vector<Student *>&student)
{
    for(auto &l:student){
        if(l->getSnum()>0){
            l->setSnum(0);
        }
    }
}


    //只显示中奖号，隐藏用户信息
void PrintfNO(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *> student)
{

    string ss="awardNumber    get prizes    ";
    string firsts(ss.size()+2,'-');
    cout<<"中奖幸运户："<<endl<<endl;
    cout<<"一等奖："<<endl;
    cout<<firsts<<endl;
    cout<<"*"<<ss<<"*"<<endl;
    for(auto &l:first){
        if(l->getSnum()==-1){
        string awards(14-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"* "<<l->getAnum()<<awards<<l->getAward()<<prizes<<"*"<<endl;
    }
    }
    cout<<firsts<<endl<<endl;



    cout<<"二等奖："<<endl;
    cout<<firsts<<endl;
    cout<<"*"<<ss<<"*"<<endl;
    for(auto &l:second){
        if(l->getSnum()==-2){
        string awards(14-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"* "<<l->getAnum()<<awards<<l->getAward()<<prizes<<"*"<<endl;
    }
    }
    cout<<firsts<<endl<<endl;


    cout<<"三等奖："<<endl;
    cout<<firsts<<endl;
    cout<<"*"<<ss<<"*"<<endl;
    for(auto &l:third){
        if(l->getSnum()==-3){
        string awards(14-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"* "<<l->getAnum()<<awards<<l->getAward()<<prizes<<"*"<<endl;
    }
    }
    cout<<firsts<<endl<<endl;

    cout<<"未中奖者："<<endl;
    cout<<firsts<<endl;
    cout<<"*"<<ss<<"*"<<endl;
    for(auto &l:student){
        string awards(14-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"* "<<l->getAnum()<<awards<<l->getAward()<<prizes<<"*"<<endl;
      }
    cout<<firsts<<endl<<endl;
}
//按顺序输出中奖用户和未中奖用户
void Printf(vector<Student *> first,vector<Student *> second,vector<Student *> third,vector<Student *> student)
{

    //                    14       7       10        10        10              15             14
    string ss="name          sex    class     num       major     awardNumber    get prizes    ";
    string firsts(ss.size()+2,'-');
           cout<<"中奖幸运户："<<endl<<endl;
           cout<<"一等奖："<<endl;
           cout<<firsts<<endl;
           cout<<"-"<<ss<<"-"<<endl;
    for(auto &l:first){
        if(l->getSnum()==-1){
        string names(13-l->name().size(),' ');
        string sexs(7-l->getSex().size(),' ');
        string classes(10-getLengths(l->getClass()),' ');
        string nums(10-getLengths(l->getNum()),' ');
        string majorss(12-l->getInformation().size(),' ');
        string awards(15-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"- "<<l->name()<<names
           <<l->getSex()<<sexs
           <<l->getClass()<<classes
           <<l->getNum()<<nums
           <<l->getInformation()<<majorss
           <<l->getAnum()<<awards
           <<l->getAward()<<prizes
           <<"-"<<endl;
    }
    }
    cout<<firsts<<endl<<endl;



    cout<<"二等奖："<<endl;
    cout<<firsts<<endl;
    cout<<"-"<<ss<<"-"<<endl;
    for(auto &l:second){
        if(l->getSnum()==-2){
        string names(13-l->name().size(),' ');
        string sexs(7-l->getSex().size(),' ');
        string classes(10-getLengths(l->getClass()),' ');
        string nums(10-getLengths(l->getNum()),' ');
        string majorss(12-l->getInformation().size(),' ');
        string awards(15-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"- "<<l->name()<<names
           <<l->getSex()<<sexs
           <<l->getClass()<<classes
           <<l->getNum()<<nums
           <<l->getInformation()<<majorss
           <<l->getAnum()<<awards
           <<l->getAward()<<prizes
           <<"-"<<endl;
    }
    }
    cout<<firsts<<endl<<endl;


    cout<<"三等奖："<<endl;
    cout<<firsts<<endl;
    cout<<"-"<<ss<<"-"<<endl;
    for(auto &l:third){
        if(l->getSnum()==-3){
        string names(13-l->name().size(),' ');
        string sexs(7-l->getSex().size(),' ');
        string classes(10-getLengths(l->getClass()),' ');
        string nums(10-getLengths(l->getNum()),' ');
        string majorss(12-l->getInformation().size(),' ');
        string awards(15-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');
        cout<<"- "<<l->name()<<names
           <<l->getSex()<<sexs
           <<l->getClass()<<classes
           <<l->getNum()<<nums
           <<l->getInformation()<<majorss
           <<l->getAnum()<<awards
           <<l->getAward()<<prizes
           <<"-"<<endl;
    }
    }
    cout<<firsts<<endl<<endl;

    cout<<"未中奖者："<<endl;

    cout<<firsts<<endl;
    cout<<"*"<<ss<<"*"<<endl;
    for(auto &l:student){
        if(l->getSnum()==0){
        string names(13-l->name().size(),' ');
        string sexs(7-l->getSex().size(),' ');
        string classes(10-getLengths(l->getClass()),' ');
        string nums(10-getLengths(l->getNum()),' ');
        string majorss(12-l->getInformation().size(),' ');
        string awards(15-getLengths(l->getAnum()),' ');
        string prizes(14-l->getAward().size(),' ');

            cout<<"* "<<l->name()<<names
           <<l->getSex()<<sexs
           <<l->getClass()<<classes
           <<l->getNum()<<nums
           <<l->getInformation()<<majorss
           <<l->getAnum()<<awards
           <<l->getAward()<<prizes
           <<"*"<<endl;
        }
    }
    cout<<firsts<<endl<<endl;

}

//获取整型变量的长度
int getLengths(int i)
{
    int len=1;
    for(;i/10>0;i/=10)
    {
        len++;
    }
    return len;
}

