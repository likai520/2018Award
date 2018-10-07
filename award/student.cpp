#include "student.h"



Student::Student(std::string name, std::string sex, int num, int classes, int snum, int anum,std::string information,std::string award)
    :m_name{name},m_sex{sex},m_num{num},m_snum{snum},m_anum{anum},m_class{classes},m_information{information},m_award{award}
{

}

std::string Student::name() const
{
    return m_name;
}

std::string Student::getSex() const
{
    return m_sex;
}

int Student::getNum() const
{
    return m_num;
}

int Student::getSnum() const
{
    return m_snum;
}

int Student::getClass() const
{
    return m_class;
}

std::string Student::getInformation() const
{
    return m_information;
}

void Student::setSnum(int snum)
{
    m_snum = snum;
}

int Student::getAnum() const
{
    return m_anum;
}

std::string Student::getAward() const
{
    return m_award;
}

void Student::setAward(const std::string &award)
{
    m_award = award;
}
