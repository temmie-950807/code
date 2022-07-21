// Problem: Ferris Wheel
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
int n, k, tmp, output=0;
vector<int> v;

signed main(void){
	fastio;
	
	// input
	cin >> n >> k;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		v.PB(tmp);
	}
	sort(v.begin(), v.end());
	
	// process
	int p1=0, p2=n-1;
	while (p1<p2){
		if (v[p1]+v[p2]<=k){
			v[p1] = -1;
			v[p2] = -1;
			p1++;
			p2--;
			output++;
		}else{
			p2--;
		}
	}
	
	int p=0, check=0;
	for (auto x : v){
		if (x==-1){
			continue;
		}else{
			check=1;
			if (x+p>k){
				p = x;
				output++;
			}else{
				p += x;
			}
		}
	}
	output += check;
	
	
	// output
	cout << output << "\n";
    return 0;
}