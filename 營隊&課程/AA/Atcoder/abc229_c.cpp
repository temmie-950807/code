// Problem: C - Cheese
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
int n, w, a, b, output=0, p=0;
vector<pair<int, int>> input;

signed main(void){
	// fastio;
	
	// input
	cin >> n >> w;
	for (int i=0 ; i<n ; i++){
		cin >> a >> b;
		input.PB({a, b});
	}
	sort(input.begin(), input.end(), greater<>());
	
	while (w>0 && p<n){
		output += input[p].first;
		input[p].second--;
		
		if (input[p].second==0){
			p++;
		}
		w--;
	}
	
	// output
	cout << output << "\n";
    return 0;
}