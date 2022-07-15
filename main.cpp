#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int MAX_SIZE = 1e5+5;
const int INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, tmp, check;
vector<int> v={1}, p;

signed main(void){
	fastio;
	
	cin >> n;
	for (int i=2 ; i<=n ; i++){
		check = 0;
		for (int j=2 ; j<i ; j++){
			if (i%j == 0){
				v.push_back(i);
				check = 1;
				break;
			}
		}
		
		if (check==0){
			p.push_back(i);
		}
	}
	
	// output
	sort(v.begin(), v.end(), greater<int>());
	sort(p.begin(), p.end(), greater<int>());
	
	if (v[0] != n){
		for (auto x : p){
			cout << x << " ";
		}
	}else{
		for (auto x : v){
			cout << x << " ";
		}
	}
    return 0;
}