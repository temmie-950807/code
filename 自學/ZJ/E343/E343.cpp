#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double w, h;
    while (cin >> w >> h){
        cout << fixed << setprecision(1) << w / (h * h / 10000) << "\n";
    }
    return 0;
}