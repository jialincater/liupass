#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    reg.show();
    reg.exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
