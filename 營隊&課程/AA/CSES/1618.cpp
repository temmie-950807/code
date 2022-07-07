#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

int n, output=0;
void solve(int n, int k){
    if (k>n){
        return;
    }else{
        output += n/k;
        solve(n, k*5);
    }
}

signed main(void){
	fastio;

    cin >> n;
    solve(n, 5);
    cout << output << "\n";
    return 0;
}