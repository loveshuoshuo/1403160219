#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef struct alist
{
    int number;
    QString name;
    int lesson1;
    int lesson2;
}student;
student s1,s2,s3,s4;
bool comparename(const alist &a1,const alist &b1)
{
    if(a1.name<b1.name)
        return 1;
    else
        return 0;
}
bool comparelesson1(const alist &a2,const alist &b2)
{
    if(a2.lesson1<b2.lesson1)
        return 1;
    else
        return 0;
}
bool comparelesson2(const alist &a3,const alist &b3)
{
    if(a3.lesson2<b3.lesson2)
        return 1;
    else
        return 0;
}


int main()
{



    s1.number=1403130209;
    s1.name="鲁智深";
    s1.lesson1=80;
    s1.lesson2=72;
    s2.number=1403140101;
    s2.name="林冲";
    s2.lesson1=82;
    s2.lesson2=76;
    s3.number=1403140102;
    s3.name="宋江";
    s3.lesson1=76;
    s3.lesson2=85;
    s4.number=1403140103;
    s4.name="武松";
    s4.lesson1=88;
    s4.lesson2=80;
    QList<student>values;
    values.append(s1);
    values.append(s2);
    values.append(s3);
    values.append(s4);
    std::sort(values.begin(),values.end(),comparename);
    std::sort(values.begin(),values.end(),comparelesson1);
    std::sort(values.begin(),values.end(),comparelesson2);








}
