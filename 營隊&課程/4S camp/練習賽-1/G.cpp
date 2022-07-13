// Problem: G. 企鵝國的總統 (Penguin the President)
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
int n, tmp, output;
vector<int> price, house;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		price.push_back(tmp);
	}
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		house.push_back(tmp);
	}
	
	for (int i=0 ; i<(1<<n) ; i++){
		bitset<20> b(i);
		// cout << b << "\n";
		
		int s = 0;
		int check = 1;
		for (int j=0 ; j<n ; j++){
			s += price[j];
			if (((i>>j)&1)==1){ // 整修
				s -= house[j];
			}
			if (s<0){
				check = 0;
				break;
			}
		}
		
		if (check==1){
			output = max(output, (int)b.count());
		}
	}
	
	// output
	cout << output << "\n";
    return 0;
}