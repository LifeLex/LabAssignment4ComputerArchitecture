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
               unsigned int  signo:1;
            };

            unsigned int ayudaEscalar:23;

            unsigned int  mantisaAux:24;
            unsigned int  mantisa1:24;
            unsigned int  mantisa2:24;
            unsigned int  p:24;
            unsigned int  acarreo:25;
            unsigned int  mantisaS:24;
            unsigned int  c1:1;
            unsigned int  c2:1;
            unsigned int  ayuda:24;
            unsigned int  mantisaAyuda:24;
            unsigned int   c:1;


            //se supone que con esto ya tienes los numeros estructurados??
            union valueU{
                numIEEE754 campos;
                float valorReal;
                unsigned int valorEntero;
            };
            valueU producto;
            valueU x;
            valueU y;
            valueU b;
            valueU r;
            valueU primab;



private slots:
    void on_adding_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
