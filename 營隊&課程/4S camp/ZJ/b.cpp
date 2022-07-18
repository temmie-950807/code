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
int n, q, tmp;
vector<int> v;

signed main(void){
	fastio;
	
	// input
	while(cin >> n >> q){
		for (int i=0 ; i<n ; i++){
			cin >> tmp;
			v.PB(tmp);
		}
		
		sort(v.begin(), v.end());
		
		for (int i=0 ; i<q ; i++){
			cin >> tmp;
			cout << (upper_bound(v.begin(), v.end(), tmp)-v.begin())%2 << "\n";
		}
	}
    return 0;
}