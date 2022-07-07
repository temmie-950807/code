#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;

    // declare
    int t, tmp;

    cin >> t;
    while (t--){
        cin >> tmp;
        if (tmp == 1){
            cout << "0\n";
        }else if (tmp==2){
            cout << "1\n";
        }else if (tmp%2==0 || tmp==3){
            cout << "2\n";
        }else{
            cout << "3\n";
        }
    }
    
    return 0;
}