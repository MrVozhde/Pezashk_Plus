#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <sabtenam.h>
#include <doctor_sabtenam.h>
#include <doctor_firstpage.h>
#include <user_firstpage.h>
#include <admin_firstpage.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

//    static QString username;
//    static QString password;


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QSqlDatabase db ;

private slots:



    void on_pushButton_clicked();

    void on_pushButton_Sabtenam_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
