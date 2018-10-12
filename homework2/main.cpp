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








}
