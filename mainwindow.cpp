#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include <bitset>
using namespace std;

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
    if(ui->lineEdit_decimal->text() != NULL && ui->lineEdit_binary->text() != NULL)
            ui->label_result->setText("Leave the result text edit empty!");
    else {
        if(ui->lineEdit_decimal->text() != NULL)
            decimalToBinary();
        else if(ui->lineEdit_binary->text() != NULL)
            binaryToDecimal();
        else
            ui->label_result->setText("Nothing set!");
    }

}

void MainWindow::decimalToBinary()
{
    QString decimal_string = ui->lineEdit_decimal->text();
        if( decimal_string.toInt() != 0) {
            int decimal_number = decimal_string.toInt();
            string binary_string = bitset<8>(decimal_number).to_string();
            QString binary_Qstring = QString::fromStdString(binary_string);
            ui->lineEdit_binary->setText(binary_Qstring);
        }
        else {
            ui->lineEdit_binary->setText("Error the value " + ui->lineEdit_decimal->text() + " is not a string");
        }
}

void MainWindow::binaryToDecimal()
{
    QString binary_string = ui->lineEdit_binary->text();
        if( binary_string.toInt(Q_NULLPTR,2) != 0) {
            int binary_base10_number = binary_string.toInt(Q_NULLPTR, 2);
            QString binary_base10_QString = QString::number(binary_base10_number);
            qDebug() << "The number is " << binary_base10_QString << endl;
            ui->lineEdit_decimal->setText(binary_base10_QString);
        }
        else {
            ui->lineEdit_decimal->setText("Error the value " + ui->lineEdit_binary->text() + " is not a string");
        }
}



void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_decimal->setText(NULL);
    ui->lineEdit_binary->setText(NULL);
}
