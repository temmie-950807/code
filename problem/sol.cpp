#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){

    // input
    cin >> a >> b >> c;

    // output
    if (a==max({a, b, c})) cout << "A";
    if (b==max({a, b, c})) cout << "B";
    if (c==max({a, b, c})) cout << "C";

    return 0;
}