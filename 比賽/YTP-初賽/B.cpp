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
vector<int> v;

signed main(void){
	fastio;
	
	// input
	cin >> n;

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            v.PB(i);
            v.PB(j);
        }
    }
    v.PB(0);

    cout << v.size() << "\n";
    for (auto x : v){
        cout << x << " ";
    }
    return 0;
}