// Problem: Creating Strings
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
#define MAX_SIZE (int)8+5

using namespace std;
using namespace __gnu_pbds;

// declare
string s;
vector<int> cnt(26, 0);
vector<string> output; 

void dfs(int n, string k){
	if (n==s.size()){
		output.push_back(k);
	}
	
	for (int i=0 ; i<26 ; i++){
		if (cnt[i]>0){
			cnt[i]--;
			dfs(n+1, k+(char)('a'+i));
			cnt[i]++; // rollback
		}
	}
}

signed main(void){
	fastio;
	
	// init
	output.clear();
	cnt.clear();
	
	// input
	cin >> s;
	for (int i=0 ; i<s.size() ; i++){
		cnt[s[i]-'a']++;
	}
	sort(s.begin(), s.end());
	
	// DFS
	dfs(0, "");
	
	// output
	cout << output.size() << "\n";
	for (auto x : output){
		cout << x << "\n";
	}
	
    return 0;
}