// Problem: B. Making Towers
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
int t, n, tmp;
int input[MAX_SIZE], max_cnt[MAX_SIZE], now_cnt[MAX_SIZE], last[MAX_SIZE];

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		memset(input, 0, sizeof(input));
		memset(max_cnt, 0, sizeof(input));
		memset(now_cnt, 0, sizeof(input));
		memset(last, -1, sizeof(input));
		
		// input
		cin >> n;
		for (int i=1 ; i<=n ; i++){
			cin >> tmp;
			input[i] = tmp;
		}
		
		// process
		for (int i=1 ; i<=n ; i++){
			if (last[input[i]]==-1){
				last[input[i]] = i;
				now_cnt[input[i]]++;
				max_cnt[input[i]] = max(max_cnt[input[i]], now_cnt[input[i]]);
			}else{
				if (abs(last[input[i]]-i)%2==1 || input[i-1]==input[i]){
					now_cnt[input[i]]++;
					max_cnt[input[i]] = max(max_cnt[input[i]], now_cnt[input[i]]);
				}
				
				last[input[i]] = i;
			}
		}

		// output
		for (int i=1 ; i<=n ; i++){
			cout << max_cnt[i] << " ";
		}   cout << "\n";	
	}
    return 0;
}