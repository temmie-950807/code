// Problem: A. Merging Arrays
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
int a, b, tmp;
vector<int> A, B, O;

signed main(void){
	fastio;
	
	// input
	cin >> a >> b;
	for (int i=0 ; i<a ; i++){
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i=0 ; i<b ; i++){
		cin >> tmp;
		B.push_back(tmp);
	}
	A.push_back(INF);
	B.push_back(INF);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	int p1=0, p2=0;
	while (p1<a || p2<b){
		if (A[p1]<B[p2]){
			O.push_back(A[p1]);
			p1++;
		}else{
			O.push_back(B[p2]);
			p2++;
		}
	}
	
	for (auto x : O){
		cout << x << " ";
	}   cout << "\n";
    return 0;
}