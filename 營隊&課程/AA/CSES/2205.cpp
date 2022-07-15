// Problem: Gray Code
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
#define MAX_SIZE (int)1e5+5

using namespace std;
using namespace __gnu_pbds;

// declare
int n;
vector<string> tmp={"0", "1"};

// function
vector<string> f(vector<string> v, int k){
	if (k==n){
		for (auto x : v){
			cout << x << "\n";
		}
		return v;
	}else{
		vector<string> a=v, b=v;
		for (int i=0 ; i<v.size() ; i++) a[i] += "0";
		for (int i=0 ; i<v.size() ; i++) b[i] += "1";
		
		reverse(b.begin(), b.end());
		a.insert(a.end(), b.begin(), b.end());
		
		return f(a, k+1);
	}
}

signed main(void){
	// fastio;
	
	// input
	cin >> n;
	
	// recursive
	f(tmp, 1);
    return 0;
}