#include "scorewindow.h"
#include "ui_scorewindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QSqlQuery>
#include <QStringList>
#include <QString>
#include <QLabel>


ScoreWindow::ScoreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScoreWindow)
{
    ui->setupUi(this);
    innitDB();

}

ScoreWindow::~ScoreWindow()
{
    delete ui;
}

void ScoreWindow::innitDB()
{
    db=QSqlDatabase::addDatabase("QMYSQL");
   db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("test");
}

void ScoreWindow::queryStudentInfo(const QString querysql)//查询学生信息
{
    QSqlQuery query(querysql);
    while(query.next()){          //填充ui
        ui->lineEditID->setText(query.value(0).toString());
        ui->lineEditName->setText(query.value(1).toString());
        ui->lineEditMajor->setText(query.value(2).toString());
        ui->lineEditClass->setText(query.value(3).toString());
    }
}

QStringList ScoreWindow::queryStudentScore(const QString querysql)//查询学生绩点
{
    QStringList queryResult;
    QSqlQuery query(querysql);
    while(query.next()){
       queryResult.append(query.value(1).toString());
       queryResult.append(query.value(2).toString());
       queryResult.append(query.value(3).toString());
    }
    return queryResult;
}

void ScoreWindow::calculatePoint(const QStringList queryResult)
{
    QStringList courseList;
    QString courseName[7];
    QString courseScore[7];
    QString courseCredit[7];
    QString courseGPA[7];
    for(int j=0;j<7;j++)
    {
        courseList.append(queryResult.at(3*j));
        courseName[j]=queryResult.at(3*j);
        courseScore[j]=queryResult.at(3*j+1);
        courseCredit[j]=queryResult.at(3*j+2);
    }
    float gpa[7];
    for(int i=0;i<7;i++){
        if(courseScore[i]=="优秀") courseGPA[i] = "4.5";
        else if(courseScore[i]=="良好")  courseGPA[i] = "3.5";
        else if(courseScore[i]=="中等")  courseGPA[i] = "2.5";
        else if(courseScore[i]=="及格")  courseGPA[i] = "1.5";
        else if(courseScore[i]=="旷考")  courseGPA[i] = "0";
        else if(courseScore[i]=="缓考")  courseGPA[i] = "0";
        else{
            float score=courseScore[i].toFloat();//转化格式计算
            if(score<60){
                courseGPA[i]="0";
                gpa[i]=0;
            }
            else{
                gpa[i]=(score-50)/10;
                courseGPA[i]=QString("%1").arg(gpa[i]);
            }
        }
    }
    ui->textEdit->clear();//每次清空表
    float avg=0;//计算平均绩点
    float sum=0;
    float creditsum=0;
    for(int i=0;i<7;i++){
        float Credit=courseCredit[i].toFloat();
        creditsum=creditsum+Credit;
        sum=sum+Credit*gpa[i];
    }
    avg=sum/creditsum;
    QString gpaavg=QString::number(avg,'f',2);//转化为两位小数的QString
    QString name=ui->lineEditName->text();
    QString str1 = "<table border='1' cellpadding='10' align='center'>"
                 " <tr  bgcolor='white'>   <td align='center' colspan='5'>  "+name+"的成绩表  </td>  </tr>"
                 " <tr>   <td align='center'>编号</td>   <td align='left'>课程名称</td>   <td align='center'>成绩</td>    <td align='center'>学分</td>   <td align='center'>绩点</td> </tr> ";
            for(int i=0;i<7;i++){
                str1.append( " <tr>   <td align='center'> "+QString("%1").arg(i+1)+" </td>   <td align='left'>"+courseName[i]+"</td>   <td align='center'>"+courseScore[i]+"</td>    <td align='center'>"+courseCredit[i]+"</td>   <td align='center'>"+courseGPA[i]+"</td>    </tr> ");
            }
            str1.append(" <tr  bgcolor='white'>   <td align='center' colspan='5'>总绩点为："+gpaavg+"</td>   </tr>"
                                                                                              " </table> ");
            ui->textEdit->insertHtml(str1);
            }
void ScoreWindow::on_btnQuery_clicked(){
    if(!db.isOpen()){
        db.open();
    }
    QString str;
    if(!db.isOpen()){
        qDebug()<<"数据库连接出错";
    }
    else if(ui->radioStNumber->isChecked())//学号查找
            str = QString("where sNumber='%1'").arg(ui->edtInput->text());
        else if(ui->radioStName->isChecked())//名字查找
            str = QString("where sName='%1'").arg(ui->edtInput->text());
    QString queryStr = QString("SELECT * FROM t_stud_info %1;").arg(str);
    queryStudentInfo(queryStr);   //查询学生信息
    queryStr = QString("select t_stud_info.sName as '姓名',t_courses.courseName as '课程名称', "
                      "t_stud_course_info.scScores as '成绩',t_courses.courseCredit as '学分' "
                      "from(t_stud_course_info inner join t_courses on t_stud_course_info.scCourseID=t_courses.courseID)"
                      "inner join t_stud_info on t_stud_info.sNumber=t_stud_course_info.scNumber "
                      "%1 "
                      "order by t_stud_course_info.scNumber;").arg(str);
    QStringList queryResult = queryStudentScore(queryStr);  //查询学生成绩
    calculatePoint(queryResult);   //计算绩点  显示结果  QTextEdit + HTML
    db.close();

}
void ScoreWindow::on_actionPL_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
       this,
       "Open Document",
       QDir::currentPath(),
       "Document files (*.csv);;All files(*.*)");
    if (!filename.isNull()) { //用户选择了文件
       // 处理文件
        qDebug()<<filename;
       QMessageBox::information(this, "Document", "Has document");
    } else
    QMessageBox::information(this, "Document", "No document");
}

void ScoreWindow::on_actionAdd_triggered()
{
    mydialog = new MYDialog(this);
    mydialog->show();

}
