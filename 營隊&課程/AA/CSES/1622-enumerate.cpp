// 0.02 s
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

signed main(void){
	fastio;
    
    vector<string> v;
    string s;

    cin >> s;
    sort(s.begin(), s.end());
    do{
        v.push_back(s);
    }while (next_permutation(s.begin(), s.end()));

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto x : v){
        cout << x << "\n";
    }
    
    return 0;
}