#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    struct numIEEE754
            {
               unsigned int fracc:23;
               unsigned int  exp:8;
               unsigned int  sign:1;
            };

            unsigned int ayudaEscalar:23;
            unsigned int  mantisaAux:24;
            unsigned int  mantisa1:24;
            unsigned int  mantisa2:24;
            unsigned int  p:24;
            unsigned int  carryOver:25;
            unsigned int  mantisaS:24;
            unsigned int  c1:1;
            unsigned int  c2:1;
            unsigned int  ayuda:24;
            unsigned int  mantisaAyuda:24;
            unsigned int   c:1;

            union valueU{
                numIEEE754 fields;
                float realValue;
                unsigned int inputValue;
            };
            valueU producto;
            valueU x;
            valueU y;
            valueU b;
            valueU r;
            valueU primab;
            valueU num1;
            valueU num2;


private slots:
    void on_adding_clicked();
    void process_input();
    bool zero_exponent(unsigned int exponent);
    int bin_to_decimal(int bin);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
