#include <iostream>
using namespace std;

int main(){
    int ip, *p;
    int &b = ip;
    p = &ip; // "指標變數(p)"必須由"取址變數(&ip)"賦值
    *p = ip;
    cin >> ip; // 24

    cout << ip << "\n"; // 24
    cout << p << "\n";  // 0x61fe0c
    cout << b << "\n";  // 24
    cout << *p << "\n"; // 24
    cout << &b << "\n"; // 0x61fe0c
    system("pause");
    return 0;
}