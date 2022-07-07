#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

signed main(void){
	fastio;
    
    int n, p=0, m=-1;
    string s;
    vector<string> v;

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> s;
        m = max((int)s.size(), m);
        v.push_back(s);
    }

    for (int i=0 ; i<m ; i++){
        for (int j=0 ; j<n ; j++){
            if (v[j].size()>i && v[j][i]>='A' && v[j][i]<='Z'){
                cout << v[j][i];
            }
        }
    }

    return 0;
}