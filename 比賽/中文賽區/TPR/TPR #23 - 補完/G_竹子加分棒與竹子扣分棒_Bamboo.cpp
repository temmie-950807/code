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
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, c, t, k1, k2, k3;
int s, output=-INF;

signed main(void){
	fastio;
	
	cin >> n >> c >> t >> k1 >> k2 >> k3;

    for (int i=0 ; i<=t ; i++){        // 加分棒次數
        for (int j=0 ; j<=t ; j++){    // 扣分棒次數
            for (int k=0 ; k<=i ; k++){ // k1棒的次數
                s = n;
                s -= j*k3;
                s += k*k1;
                s += (i-k)*k2;
                
                if (s<=c){
                    output = max(output, s);
                }
            }
        }
    }

    // output
    cout << output << "\n";
    return 0;
}