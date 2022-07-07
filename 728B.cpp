#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;

    // declare
    int t, n, tmp;
    vector<int> v;

    // input
    cin >> t;
    for (int i=0 ; i<t ; i++){
        // init
        v.clear();

        // input
        cin >> n;
        for (int j=0 ; j<n ; j++){
            cin >> tmp;
            v.push_back(tmp);
        }

        // process
        sort(v.begin(), v.end());

        // enumerate
        for (int i=n-1 ; i>=0 ; i--){
            for (int j=i-1 ; j>=0 ; j--){
                
            }
        }
    }
    return 0;
}