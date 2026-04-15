#include "../Algoritmos.h"
#include <iostream>
#include <vector>
using namespace std;

class Complejo{
    double re,im;
public:
    Complejo(){}
    Complejo(double r, double i) : re(r), im(i) {}

    Complejo operator+(const Complejo& otro){
        Complejo res(re+otro.re, im+otro.im);
        return res;
    }

    Complejo operator-(const Complejo& otro){
        Complejo res(re-otro.re, im-otro.im);
        return res;
    }

    Complejo operator*(const Complejo& otro){
        Complejo res(re*otro.re - im*otro.im, re*otro.im + otro.re * im);
        return res;
    }

    bool operator==(const Complejo& otro){
        if(re == otro.re & im == otro.im)
            return true;
        return false;
    }



    friend ostream& operator<<(ostream& os, const Complejo &comp);
    friend void operator++(Complejo &comp);
    friend istream& operator>>(istream& in, Complejo &comp);

};
void operator++(Complejo &comp){
    comp.re+=1;
    comp.im+=1;
}

// Esto no compilara porque el imaginario no tiene definido algo para la división
int main(){
    vector<Complejo> vec{Complejo(2,1),Complejo(5,-12.2),Complejo(-2,3)};
    cout << core_numeric::mean(vec);    
}