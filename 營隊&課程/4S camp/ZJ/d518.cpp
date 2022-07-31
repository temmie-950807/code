#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_pbds;

// declare
int n, t;
string s;

signed main(void){
    fastio;
    
    gp_hash_table<string, int> h;

    while (cin >> n){
        // init
        t=1;
        h.clear();

        // input
        for (int i=0 ; i<n ; i++){
            cin >> s;
            if (h[s]>0){
                cout << "Old! " << h[s] << "\n";
            }else{
                h[s]=t;
                cout << "New! " << t << "\n";
                t++;
            }
        }
    }
    
    
    return 0;
}