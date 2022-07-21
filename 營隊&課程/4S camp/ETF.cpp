// Problem: Euler Totient Function
// Memory Limit: 1536 MB
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
int t, n;

// function
int Phi(int n){
	int r = n;
	vector<int> prime;
	
	for (int i=2 ; i*i<=n ; i++){
		if (n%i==0){
			prime.PB(i);
			while (n%i==0){
				n/=i;
			}
		}
	}
	if (n>1) prime.PB(n);
	
	for (auto x : prime){
		r *= x-1;
		r /= x;
	}
	
	return r;
}

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		cin >> n;
        cout << Phi(n) << "\n";
	}
    return 0;
}