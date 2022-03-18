#include <iostream>
using namespace std;

int main(){
    int a=10;
    int *b = &a;
    int &c = a;
    cout << a << " " << &a << "\n";
    cout << b << " " << *b << " " << &b << "\n";
    cout << c << " " << &c << "\n";
    return 0;
}