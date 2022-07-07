// 78 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int unsigned long long
using namespace std;

int cnt[1000001];

signed main(void){
	fastio;
	int n, q;
    int input;
 
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> input;
        cnt[input]++;
    }
 
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> input;
        if (input>10e6) cout << "0\n";
        else cout << cnt[input] << "\n";
    }
    return 0;
}