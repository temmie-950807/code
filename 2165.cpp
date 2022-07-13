// Problem: Tower of Hanoi
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
int n, s=0;
vector<pair<int, int>> output;

// function
void f(int x, int start, int goal){
	s++;
	if (x==1){
		output.push_back({start, goal});
	}else{
		f(x-1, start, 6-start-goal);
		output.push_back({start, goal});
		f(x-1, 6-start-goal, goal);
	}
}

signed main(void){
	fastio;
	
	// input
	cin >> n;
	f(n, 1, 3);
	
	// output
	cout << s << "\n";
	for (auto x : output){
		cout << x.first << " " << x.second << "\n";
	}
    return 0;
}