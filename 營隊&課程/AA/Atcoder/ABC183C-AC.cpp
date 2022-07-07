// 7 ms	
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
    
    // declare
    int n, k, s, output=0;
    int input[8][8];
    vector<int> p;

    // input
    cin >> n >> k;
    for (int i=0 ; i<n ; i++){
        p.push_back(i);
        for (int j=0 ; j<n ; j++){
            cin >> input[i][j];
        }
    }

    // enumerate
    do{
        // init
        s=0;

        // get sum
        for (int i=1 ; i<n ; i++){
            s += input[p[i-1]][p[i]];
        }
        s += input[0][p[n-1]];

        // check
        if (s == k){
            output++;
        }

    } while (next_permutation(p.begin()+1, p.end()));

    // output
    cout << output << "\n";

    return 0;
}