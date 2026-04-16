#include "Algoritmos.h"
#include <vector>
#include <iostream>
using namespace std;

double potenciar(const double &val){
    return val * val;
}

int main(){
    //Probando todos los algoritmos
    vector<double> v{5,2.1,3.7,1.1,6.12};
    cout << core_numeric::mean(v) << endl;
    cout << core_numeric::max(v) << endl;
    cout << core_numeric::variance(v) << endl;
    cout << core_numeric::transform_reduce(v,potenciar) << endl;
    
    cout << core_numeric::sum_variadic(1,2,33,4) << endl;
    cout << core_numeric::mean_variadic(0.1,2,3,4) << endl;
    cout << core_numeric::variance_variadic(1,2,3,4) << endl;
    cout << core_numeric::variance_variadic(5.2,2.3,3.122,4.8) << endl;
    cout << core_numeric::max_variadic(1,2.7,3,4) << endl;
    
    
    return 0;
}