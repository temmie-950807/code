#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
int t, input, s, b, k, tmp;
int output, o1, o2;
int factorial[100];

signed main(void){
	fastio;

    int n;

    cin >> n;
    for (int i=-1e6 ; i<=1e6 ; i++){
        if (i*i*i*5 + i*i - i*4 == n){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}