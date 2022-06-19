// Problem: F. 糖果平分問題 (Candy)
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

// int Hash[2100000]={0};
map<string, int> Hash;

signed main(void){
	fastio;
	int t, n, m, input, output=0;
	cin >> n >> m;
	string s;
	vector<string> v;
	
	for (int i=0 ; i<n ; i++){
		// init
		s="";
		
 		for (int j=0 ; j<m ; j++){
 			cin >> input;
 			s+=(char)((input&1)+'0');
 		}

		if (Hash.find(s) == Hash.end()){
			Hash.insert({s, 1});
		}else{
			Hash[s]++;
		}
	}

	// Hash 的方法
	// for (int i=0 ; i<n ; i++){
	// 	bitset<30> b(v[i]);
	// 	int k=b.to_ulong();
	// 	if (Hash[k]>=2){
	// 		output+=Hash[k]*(Hash[k]-1)/2;
	// 		Hash[k]=0;
	// 	}
	// }

	// Map 的方法
	for (auto it=Hash.begin() ; it!=Hash.end() ; it++){
		if (it->second == 1){
			continue;
		}else{
			output += it->second*(it->second-1)/2;
		}
	}

	cout << output << "\n";

	return 0;
}