// Problem: Apartments
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int sa, sb, k, tmp, output=0;
vector<int> a, b;

signed main(void){
	fastio;
	
	// input
	cin >> sa >> sb >> k;
	for (int i=0 ; i<sa ; i++){
		cin >> tmp;
		a.PB(tmp);
	}
	for (int i=0 ; i<sb ; i++){
		cin >> tmp;
		b.PB(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	// two pointers
	int p1=0, p2=0;
	while (p1<sa && p2<sb){
		if (abs(a[p1]-b[p2])<=k){
			output++;
			p1++;
			p2++;
		}else if (a[p1]<b[p2]){
			p1++;
		}else if (a[p1]>b[p2]){
			p2++;
		}
	}
	
	// output
	cout << output << "\n";
    return 0;
}