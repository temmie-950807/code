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
int n, k, x;

// function
int f(int a){
    if (a<=k){
        return a*(a+1)/2;
    }else{
        return k*(k+1)/2 + k*(k-1)/2 - f(2*k-1-a);
    }
}

signed main(void){
	// fastio;
	
	cin >> n;
    for (int i=0 ; i<n ; i++){
        // input
        cin >> k >> x;

        // binary search
        int l=1, r=2*k-1, mid;
        while (l<=r){
            mid = (l+r)/2;

            // cout << "f(mid): " << f(mid) << "\n";

            if (l>=r  || (f(mid-1)<x && x<=f(mid))){
                cout << mid << "\n";
                break;
            }
            if (f(mid) > x){
                r = mid-1;
            }
            if (f(mid) < x){
                l = mid+1;
            }
        }

    }
    return 0;
}