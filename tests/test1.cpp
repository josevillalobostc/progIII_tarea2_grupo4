#include "../Algoritmos.h"
#include <iostream>
#include <vector>
using namespace std;

// Esto si debe compilar porque los elementos del vector cumplen con lo pedido
int main(){
    vector<double> v{4.1,2,1};
    cout << core_numeric::mean(v) << endl;
}