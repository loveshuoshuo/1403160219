#include "scorewindow.h"
#include "ui_scorewindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QSqlQuery>
#include <QStringList>
#include <QString>
#include <QLabel>
#include <QMovie>

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
