#ifndef STUDENT_H
#define STUDENT_H

//李楷 软件工程 2016051604109
#include<string>

//保存客户信息

class Student
{
public:
    Student(std::string name,std::string sex,int num,int classes,int snum,int anum,std::string information,std::string award);

    std::string name() const;
    std::string getSex() const;

    int getNum() const;
    int getSnum() const;
    int getClass() const;

    std::string getInformation() const;
    void setSnum(int snum);
    int getAnum() const;

    std::string getAward() const;
    void setAward(const std::string &award);

private:
    std::string m_name;//名字
    std::string m_sex;//性别
    int m_num;//学号
    int m_snum;//抽奖号，中一等奖后为-1,二等奖-2,三等奖-3,未中奖保持为0
    int m_anum;//抽奖号，与snum相同，一直保持不变，便于查询
    int m_class;//班级
    std::string m_award;//奖品
    std::string m_information;//专业信息
};

#endif // STUDENT_H
