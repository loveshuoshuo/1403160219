#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>


namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

typedef struct{
    QStringList stu;

} studData;




QDebug operator<< (QDebug d, const studData &data) {
    QDebugStateSaver saver(d);
    for(int i=0;i<data.stu.size();i++)
    {
    d.nospace().nospace().noquote()<<data.stu.at(i)<<"\t";
    }

    // 请补全运算符重载函数，使其可以直接输出studData结构
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:result=(d1.stu.at(0)>d2.stu.at(0));break;
    case SK::col02:result=(d1.stu.at(1)>d2.stu.at(1));break;
    case SK::col03:result=(d1.stu.at(2)>d2.stu.at(2));break;
    case SK::col04:result=(d1.stu.at(3)>d2.stu.at(3));break;
    case SK::col05:result=(d1.stu.at(4)>d2.stu.at(4));break;
    case SK::col06:result=(d1.stu.at(5)>d2.stu.at(5));break;
    case SK::col07:result=(d1.stu.at(6)>d2.stu.at(6));break;
    case SK::col08:result=(d1.stu.at(7)>d2.stu.at(7));break;
    case SK::col09:result=(d1.stu.at(8)>d2.stu.at(8));break;
    case SK::col10:result=(d1.stu.at(9)>d2.stu.at(9));break;
    case SK::col11:result=(d1.stu.at(10)>d2.stu.at(10));break;
    case SK::col12:result=(d1.stu.at(11)>d2.stu.at(11));break;
    case SK::col13:result=(d1.stu.at(12)>d2.stu.at(12));break;
    case SK::col14:result=(d1.stu.at(13)>d2.stu.at(13));break;
    case SK::col15:result=(d1.stu.at(14)>d2.stu.at(14));break;
    case SK::col16:result=(d1.stu.at(15)>d2.stu.at(15));break;
    default:;break;


    }
    return result;

}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
private:
    void output(quint8 column);
    QString filename;
    QList<studData> st;
    studData rank;


    // 请补全该类，使其实现上述要求
};
void ScoreSorter::readFile()
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QString titile(file.readLine());
    rank.stu=titile.split(" ", QString::SkipEmptyParts);
    studData presentdata;
    while(!file.atEnd())
    {
        QString line = file.readLine();

        presentdata.stu=line.split(" ",QString::SkipEmptyParts); //空Qlist则抛弃，不为空则加入
        st.append(presentdata);

    }
    file.close();
}
void ScoreSorter::doSort()
{
    for(int i=1;i<rank.stu.size();i++)
    {
        myCmp cmp(i-1);   //初始化
        std::sort(st.begin(),st.end(),cmp);
        qDebug()<<"当前是第"<<i+1<<"列排序，排序后输出为:"<<"\n"<<"\t"<<rank;
        for(int i=0;i<st.size();i++)
           qDebug()<<st.at(i);
        qDebug()<<"\n";
        output(i);


    }

}



// 请补全
ScoreSorter::ScoreSorter(QString dataFile)  //构造函数
{
    filename=dataFile;
}
void ScoreSorter::output(quint8 column)
{
    QFile file("C:/Users/12717/Desktop/a/homework02/sorted_data.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&file);
    out.setCodec("UTF-8");
    out<<QString("排序后输出，当前按照第")<<column<<QString("列排列")<<"\r\n";
    out<<"\t";
    for(int i=0;i<this->rank.stu.size();i++)
        out<<rank.stu.at(i)<<"\t";
    out<<"\r\n";
    for(int j=0;j<this->st.size();j++)
    {
        for(int i=0;i<this->rank.stu.size();i++)
            out<<this->st.at(j).stu.at(i)<<"\t";
        out<<"\r\n";

    }
    out<<"===============\n";
    file.close();

}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type);
    Q_UNUSED(context);
    QFile f("sorted_data.txt");
    f.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream out(&f);
    out<<msg<<endl;
    f.flush();
    f.close();
    QTextStream td(stdout);
    td << msg;


    // 自定义qDebug

}

int main()
{
   qInstallMessageHandler(myMessageOutput);//安装消息处理程序
    QString datafile = "C:/Users/12717/Desktop/a/homework02/data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("C:/Users/12717/Desktop/a/homework02/sorted_data.txt");
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
