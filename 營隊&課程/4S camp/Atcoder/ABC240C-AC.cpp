#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;

    // declare
    int n, x;
    int a, b;
    bitset<20000> bit[101];

    bit[0][0] = 1;
    cin >> n >> x;
    for (int i=1 ; i<=n ; i++){
        cin >> a >> b;
        bit[i] = bit[i-1]<<a | bit[i-1]<<b;
    }

    if(bit[n][x] == 1){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}