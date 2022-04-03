#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int main(){
    int n;
    while (cin >> n){
        for (int i=0 ; i<pow(2, n) ; i++){
            bitset<15> b(i);
            string output = b.to_string();

            for (int j=15-n ; j<15 ; j++){
                cout << output[j];
            }cout << "\n";
        }
    }
}