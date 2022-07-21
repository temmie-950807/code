// Problem: Two Sets
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
int n;
vector<int> a, b;

signed main(void){
	fastio;
	
	// input
	cin >> n;
	
	if ((n*n+n)%4==2){
		cout << "NO\n";
	}else{
		cout << "YES\n";
		
		if (n%4!=0){
			a.PB(1);
			a.PB(2);
			b.PB(3);
			for (int i=4 ; i<=n ; i++){
				if (i%4==0 || i%4==3){
					a.PB(i);
				}else{
					b.PB(i);
				}
			}
		}else{
			for (int i=1 ; i<=n ; i++){
				if (i%4==0 || i%4==1){
					a.PB(i);
				}else{
					b.PB(i);
				}
			}
		}
		
		cout << a.size() << "\n";
		for (auto x : a) cout << x << " ";
		cout << "\n";
		cout << b.size() << "\n";
		for (auto x : b) cout << x << " ";
		cout << "\n";
	}
    return 0;
}