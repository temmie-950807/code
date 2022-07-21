// Problem: C - Grand Garden
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
#define PB push_back
const int MAX_SIZE = 100+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, tmp, output=0;
vector<int> v(MAX_SIZE, 0), k(MAX_SIZE, 0);

signed main(void){
	fastio;
	
	// input
	cin >> n;
    for (int i=1 ; i<=n ; i++){
    	cin >> tmp;
    	v[i] = tmp;
    }
    for (int i=1 ; i<=n ; i++){
    	k[i] = v[i]-v[i-1];
    	if (k[i]>0){
    		output += k[i];
    	}
    }
    
    // output
    cout << output << "\n";
    return 0;
}