#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 5e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, a, b, c;
vector<pair<int, pair<int, int>>> v;
vector<int> output(MAX_SIZE, 0);

signed main(void){
	fastio;
	
	cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b >> c;
        v.push_back({a, {b, c}});
    }


    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (i==j) continue;
            if (v[i].first+v[j].first == v[i].second.first+v[j].second.first && v[i].second.first+v[j].second.first==v[i].second.second+v[j].second.second){
                output[i]++;
            }
        }
    }

    for (int i=0 ; i<n ; i++){
        cout << output[i] << " ";
    }
    return 0;
}