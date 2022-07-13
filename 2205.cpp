// Problem: Gray Code
// Memory Limit: 512 MB
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
int n;

// function
void f(string s, int n, bool flip){
	if (n==1 && flip==0){
		cout << s+"0\n";
		cout << s+"1\n";
	}else if (n==1 && flip==1){
		cout << s+"1\n";
		cout << s+"0\n";
	}else{
		
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	f("", n);
	
    return 0;
}