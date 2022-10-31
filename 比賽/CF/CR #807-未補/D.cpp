// Problem: D. Mark and Lightbulbs
// Memory Limit: 256 MB
// Time Limit: 1500 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int MAX_SIZE = 2e5+5;
const int INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, x, y, output;
string a, b; // a變成b
bitset<MAX_SIZE> ca, cb;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		output = 0;
		
		// input
		cin >> n;
		cin >> a >> b;
		
		// process
		for (int i=0, j=0 ; i<=n && j<=n ; i++, j++){
			if (a[i]!=b[j]){
				output = -1;
				break;
			}else{
				output += abs(i-j);
				while (a[i+1]==b[j]) i++;
				while (a[i]==b[j+1]) j++;
			}
		}
		
		// output
		cout << output << "\n";
	}
    return 0;
}