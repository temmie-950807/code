// Problem: D. 匹配任務
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
int n, tmp, check=0, k, output=0;
vector<int> v;
map<int, int> cnt;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		v.PB(tmp);
		
		cnt[tmp]++;
		if (cnt[tmp]>n/2){
			check=1;
			k = tmp;
		}
	}
	
	if (check==1){
		cout << n-cnt[k] << "\n";
		for (int i=0 ; i<n ; i++){
			if (v[i]==k){
				continue;
			}else{
				cout << k << " " << v[i] << "\n";
			}
		}
	}else{
		sort(v.begin(), v.end());
		cout << n/2 << "\n";
		
		for (int i=0 ; i<n/2 ; i++){
			cout << v[i] << " " << v[n/2+i] << "\n";
		}
	}
    return 0;
}