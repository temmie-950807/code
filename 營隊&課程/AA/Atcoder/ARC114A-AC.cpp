// Problem: A - Not coprime
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
 
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)100
using namespace std;
 
// declare
int n, tmp, output=1e18;
vector<int> input, prime={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
 
signed main(void){
	fastio;
 
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		input.push_back(tmp);
	}
	
	// enumerate
	for (int i=0 ; i<(1<<(prime.size())) ; i++){
		int s=1;
		for (int k=0 ; k<prime.size() ; k++){
			if ((i>>k)&1){
				s*=prime[k];
			}
		}
			
		int check = 1;
		for (auto x : input){
			if (__gcd(s, x)==1){
				check = 0;
			}
		}
		
		if (check){
			output = min(output, s);
		}
	}
	
	cout << output << "\n";
    return 0;
}