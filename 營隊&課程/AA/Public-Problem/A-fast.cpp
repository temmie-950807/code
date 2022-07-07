// 1450 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int unsigned long long
using namespace std;

signed main(void){
	fastio;
	int a, b, s=0;

    cin >> a >> b;

    for (int i=a ; i<=b ; i++){
        s+=i;
    }

    cout << s;
    return 0;
}