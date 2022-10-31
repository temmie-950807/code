// Problem: A. Grass Field
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
int t, a, b, c, d;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		cin >> a >> b >> c >> d;
		int s = a+b+c+d;
		
		if (s==0){
			cout << "0\n";
		}else if (s==4){
			cout << "2\n";
		}else{
			cout << "1\n";
		}
        
	}
    return 0;
}