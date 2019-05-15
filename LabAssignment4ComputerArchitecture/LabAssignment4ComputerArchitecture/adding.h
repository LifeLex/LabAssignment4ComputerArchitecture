#ifndef ADDING_H
#define ADDING_H
#include "mainwindow.h"

class Adding
{
public:
    Adding(MainWindow::valueU num1, MainWindow::valueU num2);
    MainWindow::valueU calc_addition(unsigned int mantisa1, unsigned int mantisa2);
    MainWindow::valueU num1;
    MainWindow::valueU num2;
    unsigned int  mantisaAux:24;
    unsigned int  p:24;
    unsigned int  carryOver:25;
    unsigned int  mantisaSum:24;
    unsigned int  c1:1;
    unsigned int  c2:1;
    unsigned int  c:1;
    unsigned int  temp:24;
    unsigned int  mantisaTemp:24;
};

#endif // ADDING_H
