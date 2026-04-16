#include "../Algoritmos.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NoSumable{
    int n, o;
    public:
    NoSumable() : n(0), o(0){} 
};


int main(){
    // Error porque no está definida la suma para este tipo de objetos
    vector<NoSumable> v{NoSumable(),NoSumable(),NoSumable()};
    cout << core_numeric::mean(v);
}