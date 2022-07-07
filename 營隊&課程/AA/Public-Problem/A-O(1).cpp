// 15 ms
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
    if ((a+b)%2==0){
        s = ((a+b)/2)*(b-a+1);
    }else{
        s = (a+b)*((b-a+1)/2);
    }

    cout << s;
    return 0;
}