// Problem: D - Islands War
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, q, l, r;
vector<pair<int, int>> v;

signed main(void){
	fastio;
	
	// input
	cin >> n >> q;
	for (int i=0 ; i<q ; i++){
		cin >> l >> r;
		v.PB({l, r});
	}
	sort(v.begin(), v.end());
	
	// process
	int output=1, pl=v[0].first, pr=v[0].second;
	for (auto x : v){
		if (x.second<=pl || x.first>=pr){
			// update
			output++;
			pl = x.first;
			pr = x.second;
		}else{
			pl = max(pl, x.first);
			pr = min(pr, x.second);
		}
	}
	
	// output
	cout << output << "\n";
    return 0;
}