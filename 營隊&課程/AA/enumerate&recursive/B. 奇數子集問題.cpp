// Problem: B. 奇數子集問題
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
int a, b;

// function
int f(int b, int n){
	return 2*b*n - n*n;
}

signed main(void){
	fastio;
	
	// input
	cin >> a >> b; // 在前b個奇數裡面找a
	
	// output
	if (a==0){
		cout << 0 << "\n";
		return 0;
	}else if (a==2 || a>b*b){
		cout << -1 << "\n";
		return 0;
	}else{
		for (int i=1 ; i<=b ; i++){
			if (i%2 != a%2){
				continue;
			}
			if (a>=i*i && a<=f(b, i)){
				cout << i << "\n";
				return 0;
			}
		}
	}
	
	cout << -1 << "\n";
    return 0;
}