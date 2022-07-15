// Problem: C - 1 2 1 3 1 2 1
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

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
vector<int> tmp;

// function
vector<int> f(vector<int> v, int k){
	if (n<k){
		return v;
	}else{
		v.push_back(k);
		v.insert(v.end(), v.begin(), v.end()-1);
		return f(v, k+1);
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	
	for (auto x : f(tmp, 1)){
		cout << x << " ";
	}   cout << "\n";
    return 0;
}