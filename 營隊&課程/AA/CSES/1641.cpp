// Problem: Sum of Three Values
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
int n, x, tmp;
vector<pair<int, int>> v;

signed main(void){
	fastio;
	
	// input
	cin >> n >> x;
	for (int i=1 ; i<=n ; i++){
		cin >> tmp;
		v.PB({tmp, i});
	}
	
	sort(v.begin(), v.end());
	
	int i=0, j, k;
	for (i=0 ; i<n ; i++){
		k = i+1;
		for (j=n-1 ; j>i && j>k && j>=0 ; j--){
			while (k<n && v[i].first+v[k].first+v[j].first <= x){
				if (i!=j && j!=k && v[i].first+v[k].first+v[j].first == x){
					cout << v[i].second << " " << v[k].second << " " << v[j].second << "\n";
					return 0;
				}
				k++;
			}
		}
	}
	
	cout << "IMPOSSIBLE\n";
    return 0;
}