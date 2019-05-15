#include "adding.h"
#include "mainwindow.h"
#include <iostream>

using namespace std;

Adding::Adding(MainWindow::valueU num1, MainWindow::valueU num2)
{
    this->num1 = num1;
    this->num2 = num2;
}

MainWindow::valueU Adding::calc_addition(unsigned int mantisa1, unsigned int mantisa2){
    //Step 1
    MainWindow::valueU sum;
    unsigned long aux, aux1;
    unsigned long d, k=0, g=0, r=0, st=0;
    float numAux;
    mantisaAux = 8388608;
    p = 0;

    cout<<"*************************"<<endl;
    cout<<"**       Step 2        **"<<endl;
    cout<<"*************************"<<endl;

    bool different_signs=false, operations_switched=false, commplemento_p=false;

    if(num1.fields.sign != num2.fields.sign)
        different_signs = true;

    if(num1.fields.exp < num2.fields.exp){
        //Switch the two numbers
        numAux = num1.realValue;
        num1.realValue = num2.realValue;
        num2.realValue = numAux;

        //Switch the mantisas
        aux = mantisa1;
        mantisa1 = mantisa2;
        mantisa2 = aux;

        operations_switched = true;

    }

    cout << "------ Number 1 ------" << endl;
    cout << "Sign: " << num1.fields.sign << endl; ;
    cout << "Exponent: " << QString::number(num1.fields.exp).toStdString() << endl;
    cout << "Fracc: " << QString::number(num1.fields.fracc).toStdString() << endl;
    cout << "Mantisa: " << QString::number(mantisa1, 2).toStdString() << endl;

    cout << "------ Number 2 ------" << endl;
    cout << "Sign: " << num2.fields.sign << endl; ;
    cout << "Exponent: " << QString::number(num2.fields.exp).toStdString() << endl;
    cout << "Fracc: " << QString::number(num2.fields.fracc).toStdString() << endl;
    cout << "Mantisa: " << QString::number(mantisa2, 2).toStdString() << endl;

    cout << "Boolean step 2: " << operations_switched << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 3        **"<<endl;
    cout<<"*************************"<<endl;

    sum.fields.exp = num1.fields.exp;
    d = num1.fields.exp - num2.fields.exp;

    if (d<=0){
        d=0;
    }

    cout << "Exponent sum: " << QString::number(sum.fields.exp).toStdString() << endl;
    cout<<"d: " << d << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 4        **"<<endl;
    cout<<"*************************"<<endl;

    if(different_signs){
        mantisa2 = -mantisa2;
    }

    cout<< "Mantisa 2 negative or not: " << QString::number(mantisa2,2).toStdString() << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 5        **"<<endl;
    cout<<"*************************"<<endl;

    p = mantisa2;
    cout << "p:" << QString::number(p,2).toStdString() << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 6        **"<<endl;
    cout<<"*************************"<<endl;

    if (d!=0)
        g = p>>(d-1) & 0x01;

    if (d>1)
        r = p>>(d-2) & 0x01;

    if (d>2) {
        for(int i=d-3; i>=0; i--){
            aux1 = p>>(i) & 0x01;
            st = st|aux1;
        }
    }

    cout<< "g: " << QString::number(g,2).toStdString() << endl;
    cout<< "r: " << QString::number(r,2).toStdString() << endl;
    cout<< "st: "<< QString::number(st,2).toStdString() << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 7        **"<<endl;
    cout<<"*************************"<<endl;

    if(different_signs==true){
        for(int i=d; i>0; i--){
            p = p>>1;
            p = p + mantisaAux;
        }
        cout<<"p + mantisaAux: " << QString::number(p,2).toStdString() << endl;
    } else {
        for(int i=d; i>0; i--){
            p = p>>1;
        }
        cout<<"p >> 1: " << QString::number(p,2).toStdString() << endl;
    }

    cout<<"*************************"<<endl;
    cout<<"**       Step 8        **"<<endl;
    cout<<"*************************"<<endl;

    carryOver = p + mantisa1;
    p = p + mantisa1;

    c1= carryOver>>24 & 0x01 ;

    cout << "c1: " << QString::number(c1,2).toStdString() << endl;
    cout << "p:" << QString::number(p,2).toStdString() << endl;

    if(c1==1){
        mantisaAux=8388608;
    }else if(c1==0){
        mantisaAux=000000000000000000000000;
    }

    cout<<"Carry-over: " << QString::number(carryOver,2).toStdString() << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 9        **"<<endl;
    cout<<"*************************"<<endl;

    if ((different_signs==true) && ((p>>23 & 0x01)==1) && (c1==0)){
        p = -p;
        commplemento_p = true;
    }

    cout<<"-p: " << QString::number(p,2).toStdString() << endl;
    cout<<"commplemento_p: " << commplemento_p << endl;

    cout<<"*************************"<<endl;
    cout<<"**       Step 10       **"<<endl;
    cout<<"*************************"<<endl;

    if ((different_signs==false) && (c1==1)){
        st = g|r|st;

        r = (p>>0 & 0x01);
        p = (p >> 1) + mantisaAux;
        sum.fields.exp += 1;

        cout << "st: " << st << endl;
        cout << "p: " << QString::number(p,2).toStdString() << endl;
        cout << "Exponent of the sum: " << QString::number(sum.fields.exp, 2).toStdString() << endl;
    } else {
        unsigned long a = p>>23;
        temp = p>>23;
        mantisaAux = p;

        if(temp != 1) {
            //pretty sure this if statement is wrong and they mean go on UNTIL k == 23
            // but I'm not sure. Now it says go on until temp == 1 or if k==23 at that point, run the loop one more time
            while(temp != 1 || k == 23) {
                temp = mantisaAux >> 23;
                mantisaAux = mantisaTemp<<1;
                k++;
                cout << "Auxiliary mantisa: " << mantisaTemp << endl;
            }
        }
        cout << k << endl;

        if (k==0){
            st = r|st;
            r = g;
        } else if(k > 1) {
            r = 0;
            st = 0;
        }

        //desplazar p g a la izquierda no se si es esto
        if(k > 0){
            for(unsigned long i=0; i < k; i++){
              p = p<<1;
            }
        }

        sum.fields.exp = sum.fields.exp - k;

        cout << "st: " << st << endl;
        cout <<"r: " << r << endl;
        cout <<"p:" << QString::number(p,2).toStdString() << endl;
        cout << "Exponent of the sum:" << QString::number(sum.fields.exp, 2).toStdString() << endl;
    }

    cout<<"*************************"<<endl;
    cout<<"**       Step 11       **"<<endl;
    cout<<"*************************"<<endl;

    if( ((r==1) && (st==1)) || ((r==1) && (st==0) && (p & 0x01==1)) ) {
        carryOver=p+1;
        p++;
        c2 = carryOver>>(24) & 0x01;
        if(c2==1){
            p = (p >> 1);
            c2 = 0;
            sum.fields.exp++;
        }
    }
    mantisaSum = p;

    cout<<"*************************"<<endl;
    cout<<"**       Step 12       **"<<endl;
    cout<<"*************************"<<endl;

    if((operations_switched==false)&&(commplemento_p==true)){
        sum.fields.sign = num2.fields.sign;
    }else{
        sum.fields.sign = num1.fields.sign;
    }

    cout<<"*************************"<<endl;
    cout<<"**       Step 13       **"<<endl;
    cout<<"*************************"<<endl;

    sum.fields.exp = 127 + sum.fields.exp;
    sum.fields.fracc = mantisaSum;

    cout << "------ Result Addition ------" << endl;
    cout << "Sign: " << sum.fields.sign << endl; ;
    cout << "Exponent: " << QString::number(sum.fields.exp).toStdString() << endl;
    cout << "Fracc: " << QString::number(sum.fields.fracc).toStdString() << endl;
    cout << "Mantisa: " << QString::number(mantisaSum, 2).toStdString() << endl;
    cout << "Result: " << sum.realValue << endl;

    return sum;
}
