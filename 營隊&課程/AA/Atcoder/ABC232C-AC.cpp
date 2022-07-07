#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
    
    int m, n; // line, ball
    int a, b; // line start, line end
    int A[15][15], B[15][15];
    vector<int> replace;

    cin >> n >> m;

    // init
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            A[i][j] = 0;
            B[i][j] = 0;
        }
    }

    // input
    
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        B[a][b] = 1;
        B[b][a] = 1;
    }

    // get "replace"
    replace.push_back(0);
    for (int i=1 ; i<=n ; i++){
        replace.push_back(i);
    }

    // enumerate
    do{
        // declare
        bool check = 1;

        // replace
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                if (A[i][j] != B[replace[i]][replace[j]]){
                    check = 0;
                }
            }
        }

        // check
        if (check){
            cout << "Yes\n";
            return 0;
        }
    } while (next_permutation(replace.begin()+1, replace.end()));
    
    // output
    cout << "No\n";
    return 0;
}