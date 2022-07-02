// 32 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
signed main(void){
	fastio;
	
    int n, tmp, output=0, s=0;
    vector<int> v;

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        s += tmp;
        v.push_back(tmp);
    }

    for (int i=0 ; i<n ; i++){
        output += (v[i]*v[i]);
    }   output *= n;
        output -= s*s;

    cout << output << "\n";
    return 0;
}