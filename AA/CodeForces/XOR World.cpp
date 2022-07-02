// 6 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int unsigned long long
using namespace std;

int F(int a, int b){
    if (b%2==0){
        // 偶數
        return ((b%4)/2)^b;
    }else {
        // 奇數
        return ((b+1)/2)%2;
    }
}

signed main(void){
	fastio;
	int a, b;

    cin >> a >> b;

    cout << (F(0, a-1)^F(0, b));
    return 0;
}