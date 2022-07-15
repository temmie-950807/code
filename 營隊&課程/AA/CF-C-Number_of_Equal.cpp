// Problem: C. Number of Equal
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
int n, m, tmp, output=0;
vector<int> a, b;

signed main(void){
	// fastio;
	
	// input
	cin >> n >> m;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i=0 ; i<m ; i++){
		cin >> tmp;
		b.push_back(tmp);
	}
	a.push_back(INF);
	b.push_back(INF);
	
	int i=0, j=0, x, y;
	while (i<n || j<m){
		x=0;
		y=0;
		
		tmp = a[i];
		for ( ; i<n && a[i]==tmp ; i++){
			x++;
		}
		
		for ( ; j<m && b[j]<=tmp ; j++){
			if (b[j]==tmp) y++;
		}
		
		output += x*y;
	}
	
	// output
	cout << output << "\n";
    return 0;
}