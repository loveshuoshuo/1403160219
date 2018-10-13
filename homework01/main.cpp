#include <QDebug>
#include <QList>
#include <algorithm>
#include <QCoreApplication>
#include <vector>

#define word_LLO(xx) ((((unsigned)(xx))>>(8*0))&0xff)  /*3*/
#define word_HLO(xx) ((((unsigned)(xx))>>(8*1))&0xff)  /*1*/
#define word_LHI(xx) ((((unsigned)(xx))>>(8*2))&0xff)  /*4*/
#define word_HHI(xx) ((((unsigned)(xx))>>(8*3))&0xff)  /*2*/
#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )
int main()
{
    qint8 m,n,j,k;
    unsigned a=0x12345678;                 /*输入的值*/
    qDebug("原始值：0x%x==%d\n",a,a);       /*原始值*/
    m=word_HHI(a);
    n=word_LHI(a);
    j=word_HLO(a);
    k=word_LLO(a);
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d\n",m,m,n,n,j,j,k,k);    /*取出的值*/
    qDebug("最高八位与次高八位最大值：0x%x<%d>\n",MAX(m, n),MAX(m, n));     /*最高八位与次高八位最大值*/
    qDebug("最低八位与次低八位最小值：0x%x<%d>\n",MIN(j, k),MIN(j, k));     /*最低八位与次低八位最小值*/
    qDebug("重新组合后数值为：0x%x<%d>",((word_HLO(a))<<(8*3))|((word_HHI(a))<<(8*2))|((word_LLO(a))<<(8*1))|((word_LHI(a))<<(8*0)),((word_HLO(a))<<(8*3))|((word_HHI(a))<<(8*2))|((word_LLO(a))<<(8*1))|((word_LHI(a))<<(8*0)));
    QList<qint8> values;                                                 /*写入values*/
    values<<m<<n<<j<<k;
    qDebug("排序前：");
    qDebug()<<values;                                                    /*排序前输出*/
    std::sort(values.begin(),values.end(),std::greater<qint8>());        /*由大到小排序*/
    qDebug("排序后：");
    qDebug()<<values;                                                    /*排序后输出*/
}
