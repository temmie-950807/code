// Problem: Creating Strings II
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
const int MAX_SIZE = 1e6+5;
const int INF = 1e18;
const int MOD = 1000000007;
using namespace std;
using namespace __gnu_pbds;

// declare
int output=1;
vector<int> fac(MAX_SIZE);
string s;

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
	
	// pre-process
	fac[0] = 1;
	for (int i=1 ; i<MAX_SIZE ; i++){
		fac[i] = fac[i-1]*i%MOD;
	}
	
	// input
	cin >> s;
	sort(s.begin(), s.end());
	
	// process
	output = fac[s.size()];
	
	int p=0, cnt=1;
	for (int i=1 ; i<s.size() ; i++){
		if (s[i]==s[p]){
			cnt++;
			continue;
		}else{
			output = output * qp(fac[cnt], MOD-2, MOD) % MOD;
			p = i;
			cnt = 1;
		}
	}
	
	// output
	output = output * qp(fac[cnt], MOD-2, MOD) % MOD;
	cout << output << "\n";
    return 0;
}