#include "dialog.h"
#include "ui_dialog.h"
#include "qdebug.h"
#include "QFile"
#include "QVector"
#include "QTime"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
//QVector<QTime> timeA;
void Dialog::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog::on_pushButton_clicked()
{
    QString acc = ui->lineEdit->text();
    QString pw1 = ui->lineEdit_2->text();
    QString pw2 = ui->lineEdit_3->text();
    qDebug()<<acc<<" "<<pw1<<" "<<pw2;
    if(pw1==pw2&&acc!=""&&pw1 != "")
    {
        QFile file("/Users/Jialin/finpass/in.txt");
        if(!file.exists())
        {
            qDebug()<<"file doesn't exist";
            ui->label_5->setText("file doesn't exist");
        }
        if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
        {
            qDebug()<<"openfail";
            ui->label_5->setText("OpenFail");
            return;
        }
        const QString line = acc+" "+pw1;
        QTextStream out(&file);
        out<<acc<<" "<<qHash(pw1)<<endl;
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        file.close();
        this->close();
    }
    else
    {
        ui->label_5->setText("all blanks must be written");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        return;
    }
}
//QTime t;
//void Dialog::on_lineEdit_2_selectionChanged()
//{
//    t.restart();
//    timeA.append(t.elapsed());
//    t.restart();
//}
