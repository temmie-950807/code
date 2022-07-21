// Problem: B. 心算
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
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n;
vector<int> output;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	
	if (n==1){
		cout << "1\n";
		return 0;
	}
	
	// greedy
	int p=9;
	while (n>1 && p>=2){
		// cout << "n: " << n << " p: " << p << "\n";
		if (n%p!=0){
			p--;
		}else{
			output.PB(p);
			n/=p;
		}
	}
	
	// output
	if (n==1){
		reverse(output.begin(), output.end());
		for (auto x : output) cout << x;
	}else{
		cout << "-1\n";
	}
    return 0;
}