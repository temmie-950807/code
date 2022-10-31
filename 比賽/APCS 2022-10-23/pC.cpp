#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;

// 宣告
int f(int x){
    int n;
    cin >> n;

    if (n==0){
        return 0;
    }
    
    int add=0;
    if (x!=-1){
        add=abs(x-n);
    }
    
    if (n%2==0){
        return add+f(n)+f(n);
    }else{
        return add+f(n)+f(n)+f(n);;
    }
}


signed main(void){
    // 輸入
    cout << f(-1) << "\n";    
    return 0;
}