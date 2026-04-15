#include "../Algoritmos.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Complejo{
    double re,im;
public:
    Complejo(){}
    Complejo(double r, double i) : re(r), im(i) {}

    double modulo() const{
        double op = pow(re,2) + pow(im,2);
        return sqrt(op);
    }
    
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

    Complejo operator/(double n) {
        return Complejo(re/n,im/n);
    }
    
    bool operator>(const Complejo& otro) const{
        if(otro.modulo() < this -> modulo()){
            return true;
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const Complejo &comp);

};
ostream& operator<<(ostream& os, const Complejo &comp){
    os << comp.re;
    if(comp.im != 0)
        os << " + " << comp.im << "i";
    return os;
}

// Aquí si compila, porque la clase Complejo sí tiene definida la división
int main(){
    vector<Complejo> vec{Complejo(2,1),Complejo(5,-8),Complejo(-2,3)};
    cout << core_numeric::mean(vec) << endl;
    // Además, esto también compilará por definir el operador < para la clase
    cout << core_numeric::max(vec) << endl;
}