#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 8e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, m, a, b, output=0;
map<int, int> ma;

signed main(void){
	fastio;
	
	// input
	cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        output += 400;
        output += (n-1)*200;
    }

    // output
    cout << output << "\n";
    return 0;
}