#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnable(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    changeEnable(money);
}

void Widget::changeEnable(int mo){
    ui->pbCoffee->setEnabled(mo>=100);
    ui->pbTea->setEnabled(mo>=200);
    ui->pbTang->setEnabled(mo>=300);
    ui->pbReset->setEnabled(mo>0);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}



void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    int f_hund = money/500;
    int hund = (money%500)/100;
    int ten = (money%500%100)/10;
    mb.information(nullptr,"RESET",QString("500won : %1, 100won : %2, 10won : %3").arg(f_hund).arg(hund).arg(ten));
    changeMoney(-money);
}
//0won reset disable


