// 6084 ms
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    unsigned long long int a, b, s=0;

    cin >> a >> b;

    for (unsigned long long int i=a ; i<=b ; i++){
        s+=i;
    }

    cout << s;
    return 0;
}