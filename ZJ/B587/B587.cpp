#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    long long int n, l[40]={1, 2, 3};
    for (int i=3 ; i<=31 ; i++){
        if (i%2 == 1){
            l[i]=l[i-1]*2 + l[i-2];
        }else{
            l[i]=l[i-1]+l[i-2];
        }
    }

    while (cin >> n && n!=-1){
        if (n%2 == 1) cout << 0 << "\n";
        else cout << l[n] << "\n";
    }
    
    return 0;
}