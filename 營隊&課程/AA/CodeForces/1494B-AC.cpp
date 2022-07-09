// Problem: B. Berland Crossword
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n, u, r, d, l;
int A, B, C, D;       // 中間要有數量
bool check;

signed main(void){
	fastio;
	
	// input
	cin >> t;
	while (t--){
		// init
		check = 0;
		
		// input
		cin >> n >> u >> r >> d >> l;
        A = u;
        B = r;
        C = d;
        D = l;
        
        // enumerate
        for (int i=0 ; i<16 ; i++){
        	A = u;
	        B = r;
	        C = d;
	        D = l;
	        
	        
        	if (i&1){
        		A--;
        		B--;
        	}
        	if (i&2){
        		B--;
        		C--;
        	}
        	if (i&4){
        		C--;
        		D--;
        	}
        	if (i&8){
        		D--;
        		A--;
        	}
        	
        	if (A>=0 && B>=0 && C>=0 && D>=0 && A<=n-2 && B<=n-2 && C<=n-2 && D<=n-2){
        		check = 1;
        	}
        }
        
        // output
        if (check){
        	cout << "YES\n";
        }else{
        	cout << "NO\n";
        }
	}
    return 0;
}