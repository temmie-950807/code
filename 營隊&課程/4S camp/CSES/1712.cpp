// Problem: Exponentiation II
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
int t, a, b, c;

int qp(int b, int p, int m){
	int k = 1;
	while (p){
		if (p&1){
			k = k*b%m;
		}
		b = b*b%m;
		p >>= 1;
	}
	return k;
}

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		cin >> a >> b >> c;
        cout << qp(a, qp(b, c, 1000000006), 1000000007) << "\n";
	}
    return 0;
}