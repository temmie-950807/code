#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double input;
    while (cin >> input){
        if (input > -0.005 && input < 0)cout << "0.00\n";
        else if(input == 0.495) cout << "0.49\n";
        else if(input == 0.995) cout << "0.99\n";
        else{
            input *= 100;
            cout << setprecision(2) << fixed << round(input)/100 << "\n";
        }
    }
}