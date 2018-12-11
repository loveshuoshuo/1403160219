#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "mydialog.h"

namespace Ui {
class ScoreWindow;
}



class ScoreWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScoreWindow(QWidget *parent = 0);
    ~ScoreWindow();
    void innitDB();
protected:
    void queryStudentInfo(const QString querysql);  //查询学生信息
    QStringList queryStudentScore(const QString querysql);  //查询学生绩点
    void calculatePoint(const QStringList queryResult);  //计算绩点显示表格


private slots:
    void on_btnQuery_clicked();
    void on_actionPL_triggered();
    void on_actionAdd_triggered();

private:
    QSqlDatabase db;
    Ui::ScoreWindow *ui;
    MYDialog* mydialog;
    QStringList stuList;

};

#endif // SCOREWINDOW_H
