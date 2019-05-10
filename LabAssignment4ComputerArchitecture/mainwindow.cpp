#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adding.h"
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
    mantisaAux=8388608;
    valueU num1;
    num1.valorReal= ui->number1->text().toFloat();

    valueU num2;
    num2.valorReal= ui->number2->text().toFloat();

    ui->number1Hex->setText(QString::number(num1.valorEntero,16));
    ui->numbe2Hex->setText(QString::number(num2.valorEntero,16));
    if(num1.campos.exp == 11111111 && num2.campos.exp == 11111111){
        ui->label_RESULT->setText("NaN");
    }
    else if(num1.campos.exp == 11111111 || num2.campos.exp == 11111111){
        ui->label_RESULT->setText("NaN");
    }
    if(num1.campos.exp == 00000000 || num2.campos.exp == 00000000){
        ui->label_RESULT->setText("NaN");
    }
    else{

        if(esDenormal(num1.campos.exp)){
        num1.campos.exp=-126;
        mantisa1=num1.campos.fracc+mantisaAux;

        }else{
        num1.campos.exp=num1.campos.exp-127;
        mantisa1=num1.campos.fracc+mantisaAux;
        }
        if(esDenormal(num2.campos.exp)){
        num2.campos.exp=-126;
        mantisa2=num2.campos.fracc+mantisaAux;
        }else{
        num2.campos.exp=num2.campos.exp-127;
        mantisa2=num2.campos.fracc+mantisaAux;
        }

        cout<<"*************************"<<endl;
        cout<<"**       paso1         **"<<endl;
        cout<<"*************************"<<endl;

        cout<<"Numero 1 -> signo "<<num1.campos.signo<<" exponente "<<QString::number(num1.campos.exp,2).toStdString()<<" fracc "<<QString::number(num1.campos.fracc,2).toStdString()<<" mantisa "<<QString::number(mantisa1,2).toStdString()<<endl;
        cout<<"Numero 2 -> signo "<<num2.campos.signo<<" exponente "<<QString::number(num2.campos.exp,2).toStdString()<<" fracc "<<QString::number(num2.campos.fracc,2).toStdString()<<" mantisa "<<QString::number(mantisa2,2).toStdString()<<endl;

        //Elige que operacion se va a realizar:
}
}
