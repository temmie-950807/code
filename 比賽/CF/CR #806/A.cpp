// Problem: A. YES or YES?
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t;
string s;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		cin >> s;
		if (s.size()==3 && (s[0]=='Y' || s[0]=='y') && (s[1]=='E' || s[1]=='e') && (s[2]=='S' || s[2]=='s')){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
        
	}
    return 0;
}