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
int t, n, tmp;
int v, cnt_v;
vector<int> input;
priority_queue<pair<int, int>> pq;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		input.PB(tmp);
		cnt[tmp]++;
		if (cnt[tmp]>cnt_v){
			v = tmp;
			cnt_v = cnt[tmp];
		}
	}
	
	// output
	cout << n-cnt_v << "\n";
	for (int i=0 ; i<n ; i++){
		if (input[i]==v){
			continue;
		}else{
			cout << input[i] << " " << v << "\n";
		}
	}
    return 0;
}