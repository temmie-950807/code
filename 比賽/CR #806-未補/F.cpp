// Problem: F. Yet Another Problem About Pairs Satisfying an Inequality
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
#define MAX_SIZE (int)2e5+5

using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, tmp, total, output;
vector<int> a(MAX_SIZE), b(MAX_SIZE);

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		total = 0;
		output = 0;
		a.clear(); // 紀錄輸入
		b.clear(); // 紀錄第i項之前有多少項符合規定(index>value)
		
		// input
		cin >> n;
        for (int i=1 ; i<=n ; i++){
        	cin >> tmp;
        	a[i] = tmp;
        	
        	if (a[i]<i) total++;
        	b[i] = total;
        }
        
        // process
        for (int i=1 ; i<=n ; i++){
        	if (a[i]<i && a[i]-1>=0){
        		output += b[a[i]-1];
        	}
        }
        
        // output
        // for (int i=1 ; i<=n ; i++) cout << a[i] << " ";
        // cout << "\n";
        // for (int i=1 ; i<=n ; i++) cout << b[i] << " ";
        // cout << "\n\n";
        cout << output << "\n";
	}
    return 0;
}