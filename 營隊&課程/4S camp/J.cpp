// Problem: J. 調色盤 (Colors)
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
int n, q, tmp;
int all_gcd;
vector<int> input;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		input.PB(tmp);
	}
	
	all_gcd = input[0];
	for (int i=1 ; i<n ; i++){
		all_gcd = __gcd(all_gcd, input[i]);
	}
	
	// cout << "gcd: " << all_gcd << "\n";
	
	cin >> q;
	for (int i=0 ; i<q ; i++){
		cin >> tmp;
		if ((tmp-1115)%all_gcd==0){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
    return 0;
}