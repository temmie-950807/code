// Problem: C. Number of Segments with Small Sum
// Memory Limit: 1024 MB
// Time Limit: 1000 ms

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
int n, s, tmp, output=0;
vector<int> v;

signed main(void){
	fastio;
	
	// init
	v.clear();
	
	// input
	cin >> n >> s;
	v.push_back(0);
	for (int i=1 ; i<=n ; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(INF);
	partial_sum(v.begin(), v.end(), v.begin());
	
	// process
	int p1, p2=0;
	for (p1=1 ; p1<=n ; p1++){
		while (v[p2+1]-v[max((int)0, p1-1)] <= s) p2++;
		// cout << p1 << " " << p2 << "\n";
		output += p2-p1+1;
	}
	
	// output
	cout << output << "\n";
    return 0;
}