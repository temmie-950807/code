#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;

    // declare
    int t, n, tmp, cnt;
    vector<int> v;
    map<int, int> m;

    cin >> t;
    while (t--){
        // init
        v.clear();
        m.clear();
        cnt = 0;

        // input
        cin >> n;

        // process
        for (int i=0 ; i<n ; i++){
            cin >> tmp;
            v.push_back(tmp);
            m[v[i]] = 0;
        }

        // get rank
        for (auto &it : m){
            it.second = ++cnt;
        }

        // output
        for (int i=0 ; i<n ; i++){
            cout << m[v[i]] << " ";
        }   cout << "\n";
    }
    return 0;
}