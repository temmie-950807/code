// Problem: O. 完美群體 (Perfect group)
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	// fastio;
	int n, k, cnt=0, pointer, input; // cnt: 總共有幾個環
	vector<int> v(300000, 0);
	vector<int> go(300000, 0);
	
	cin >> n >> k;
	if (k>n) cout << -1 << "\n";
	else{
		v.push_back(0);
		for (int i=1 ; i<=n ; i++){
			cin >> input;
			v[i]=input;
		}

		for (int i=1 ; i<=n ; i++){
			if (go[i]==0){
				go[i]=1;
				pointer=v[i];
				while (go[pointer]==0){
					go[pointer]=1;
					pointer=v[pointer];
				}
				cnt++;
			}else{
				continue;
			}
		}

		cout << abs(k-cnt) << "\n";
	}
	return 0;
}