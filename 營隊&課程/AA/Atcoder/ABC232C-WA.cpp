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
    bool check;
    string output="No";
    vector<int> A[15], B[15], C[15];
    vector<int> replace;
 
    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        B[a].push_back(b);
        B[b].push_back(a);
    }
 
    // sort, get "replace"
    replace.push_back(0);
    for (int i=1 ; i<=8 ; i++){
        sort(A[i].begin(), A[i].end());
        replace.push_back(i);
    }
 
    // enumerate
    do{
        // replace element
        for (int i=1 ; i<=8 ; i++){
            for (int j=0 ; j<B[i].size() ; j++){
                B[i][j] = replace[B[i][j]];
            }
        }
 
        // replace vector
        for (int i=1 ; i<=8 ; i++){
            sort(B[i].begin(), B[i].end());
            C[replace[i]] = B[i];
        }
        for (int i=1 ; i<=8 ; i++){
            B[i] = C[i];
        }
 
        // check
        check = 1;
        for (int i=1 ; i<=8 ; i++){
            if (A[i] != B[i]){
                check = 0;
                break;
            }
        }
 
        if (check){
            output = "Yes";
            break;
        }
 
    } while (next_permutation(replace.begin()+1, replace.end()));
    
    // output
    cout << output << "\n";
    
    return 0;
}