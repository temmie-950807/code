// Problem: B - Many Oranges
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

signed main(void){
	fastio;
	
	int a, b, w;
	cin >> a >> b >> w;
	
	int mi=1e9,ma=0;
	for(int i=1 ; i<=1000000 ; i++){    // 窮舉所有可能的答案
	    if(a*i<=1000*w && 1000*w<=b*i){ // 確認有可能的答案
			mi=min(mi,i);
	    	ma=max(ma,i);
	    }
	}
	if(ma==0) cout << "UNSATISFIABLE";
	else cout << mi << " " << ma;
    return 0;
}