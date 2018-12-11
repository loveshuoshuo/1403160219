#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QMainWindow>
#include <QtSql>

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

private:
    Ui::ScoreWindow *ui;
    QSqlDatabase db;
};

#endif // SCOREWINDOW_H
