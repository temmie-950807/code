// Problem: B. 城市配對數量
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long

const int MAX_SIZE = 1e5+5;
const int INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

// declare
int n, tmp, cnt, output=0;
vector<int> A, B;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	for (int i=1 ; i<=n ; i++){
		cin >> tmp;
		A.push_back(tmp-i);
		B.push_back(tmp+i);
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	for (int i=0, j ; i<n ; i=j){
		cnt = 0;
		for (j=i+1 ; j<n && A[i]==A[j] ; j++){
			cnt++;
			output += cnt;
		}
	}
	
	for (int i=0, j ; i<n ; i=j){
		cnt = 0;
		for (j=i+1 ; j<n && B[i]==B[j] ; j++){
			cnt++;
			output += cnt;
		}
	}
	
	
	cout << output*2 << "\n";
    return 0;
}