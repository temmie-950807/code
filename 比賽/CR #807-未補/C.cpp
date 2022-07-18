// Problem: C. Mark and His Unfinished Essay
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int MAX_SIZE = 1e5+5;
const int INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

// declare
int t, s_size, c, q, l, r, k;
string s;
vector<int> v; // 每個複製後的長度
vector<pair<int, int>> co;

// function
int y, ql;
char f(int x){
	if (x > s_size){
		y = lower_bound(v.begin(), v.end(), x)-v.begin();
		ql = co[y].first;
		
		// cout << "y: " << y << " ql: " << ql << "\n";
		// cout << "next_x: " << x-v[y-1]+ql-1 << "\n";
		
		return f(x-v[y-1]+ql-1);
	}else{
		return s[x-1];
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		v.clear();
		co.clear();
		
		// input
		cin >> s_size >> c >> q >> s;
		v.push_back(s_size);
		co.push_back({0, 0});
		
        for (int i=0 ; i<c ; i++){
        	cin >> l >> r;
        	v.push_back(v[v.size()-1]+r-l+1);
        	co.push_back({l, r});
        }
        
        // cout << "\nthis is v: \n";
        // for (auto x : v){
        	// cout << x << " ";
        // }   cout << "\n\n";
        
        // process
        for (int i=0 ; i<q ; i++){
        	cin >> k;
        	cout << f(k) << "\n";
        }
	}
    return 0;
}