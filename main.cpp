#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    
    cin >> n;
    while (n>=10){
        int k=0;
        while (n!=0){
            k+=n%10;
            n=n/10;
        }
        n=k;
    }
    cout << n << endl;

    return 0;
}
