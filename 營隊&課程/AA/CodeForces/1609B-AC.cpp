// 78 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
signed main(void){
	fastio;
	
    int n, q;
    int pos;
    int total=0;
    string s;
    char c;

    cin >> n >> q >> s;
    
    // get total;
    for (int i=0 ; i<n-2 ; i++){
        total += (s.substr(i, 3)=="abc");
    }
    
    // anser query
    for (int i=0 ; i<q ; i++){
        cin >> pos >> c;
        pos--;

        for (int i=max((int)0, pos-2) ; i<min(n-2, pos+2) ; i++){
            total -= (s.substr(i, 3)=="abc");
        }
        s[pos]=c;
        for (int i=max((int)0, pos-2) ; i<min(n-2, pos+2) ; i++){
            total += (s.substr(i, 3)=="abc");
        }

        cout << total << "\n";
    }
    return 0;
}