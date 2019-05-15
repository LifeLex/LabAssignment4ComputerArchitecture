#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adding.h"
#include <iostream>

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

void MainWindow::on_adding_clicked()
{
    process_input();
    Adding *add = new Adding(num1, num2);
    valueU sum = add->calc_addition(mantisa1, mantisa2);
    ui->result->setPlainText(QString::number(sum.realValue));
    ui->resultHex->setPlainText(QString::number(sum.inputValue,16));
}

void MainWindow::process_input() {
    mantisaAux=8388608;

    // Set textfieldsprocess_input();
    num1.realValue = ui->number1->toPlainText().toFloat();
    ui->number1Hex->setPlainText(QString::number(num1.inputValue, 16));

    num2.realValue = ui->number2->toPlainText().toFloat();
    ui->number2Hex->setPlainText(QString::number(num2.inputValue, 16));

    if(num1.fields.exp == 11111111 || num2.fields.exp == 11111111) {
        ui->result->setPlainText("NaN");
    }

    if(num1.fields.exp == 00000000 || num2.fields.exp == 00000000) {
        ui->result->setPlainText("NaN");
    } else {

        // Initialise exponent and mantisa
        if(zero_exponent(num1.fields.exp)) {
            num1.fields.exp = -126;
        } else {
            num1.fields.exp -= 127;
        }

        if(zero_exponent(num2.fields.exp)) {
            num2.fields.exp = -126;
        } else {
            num2.fields.exp = num2.fields.exp - 127;
        }

        mantisa1 = num1.fields.fracc + mantisaAux;
        mantisa2 = num2.fields.fracc + mantisaAux;
    }

    // Print some extra information about input
    cout << "*************************" << endl;
    cout << "**       Step 1        **" << endl;
    cout << "*************************" << endl;

    cout << "------ Number 1 ------" << endl;
    cout << "Sign: " << num1.fields.sign << endl; ;
    cout << "Exponent: " << QString::number(num1.fields.exp, 2).toStdString() << endl;
    cout << "Fracc: " << QString::number(num1.fields.fracc).toStdString() << endl;
    cout << "Mantisa: " << QString::number(mantisa1, 2).toStdString() << endl;

    cout << "------ Number 2 ------" << endl;
    cout << "Sign: " << num2.fields.sign << endl; ;
    cout << "Exponent: " << QString::number(num2.fields.exp, 2).toStdString() << endl;
    cout << "Fracc: " << QString::number(num2.fields.fracc).toStdString() << endl;
    cout << "Mantisa: " << QString::number(mantisa2, 2).toStdString() << endl;

}

bool MainWindow::zero_exponent(unsigned int exponent) { return (exponent==0); }

int MainWindow::bin_to_decimal(int bin)
{

    int rem, temp, dec = 0, b = 1;

     temp = bin;

     while (temp > 0)

     {
         rem = temp % 10;
         dec = dec + rem * b;
         b *= 2;
         temp /= 10;
     }

    return dec;
}
