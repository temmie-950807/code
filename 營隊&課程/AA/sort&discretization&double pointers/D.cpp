// Problem: D. 三角形們
// Memory Limit: 256 MB
// Time Limit: 1500 ms

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
int n, tmp, output=0;
vector<int> v;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	// process
	for (int i=0 ; i<n ; i++){
		int k=i+2; // k為最大值的pointer
		for (int j=i+1 ; j+1<n ; j++){
			while (k<n && v[i]+v[j]>v[k]) k++;
			// cout << "i: " << i << " j: " << j << " k: " << k << "\n";
			output += k-j-1;
		}
	}
	
	// output
	cout << output << "\n";
    return 0;
}