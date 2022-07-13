// Problem: A. 水題 (Water Problem)
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
int t, x, n, tmp, output=0;
vector<int> input;

signed main(void){
	fastio;
	
	// input
	cin >> t >> x;
	while (t--){
		cin >> tmp;
        input.push_back(tmp);
	}
	
	// process
	tmp = 0;
	for (auto k : input){
		if (k%x==0){
			tmp++;
			output += tmp;
		}else{
			tmp = 0;
		}
	}
	
	// output
	cout << output << "\n";
    return 0;
}