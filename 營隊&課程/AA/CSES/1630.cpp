// Problem: Tasks and Deadlines
// Memory Limit: 512 MB
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
int n, a, d, output=0;
vector<pair<int, int>> v;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> a >> d;
		v.PB({a, d});
	}
	sort(v.begin(), v.end());
	
	int t=0, p=0;
	while (p<v.size()){
		t += v[p].first;
		output += v[p].second-t;
		p++;
	}
	
	// output
	cout << output << "\n";
    return 0;
}