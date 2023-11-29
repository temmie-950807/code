#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0);
using namespace std;

// declare
const int MAX_N = 26;

int n, m;
int a, b;
int inv[MAX_N];
char dp[1<<MAX_N];

void solve1(){

    // input
    cin >> n >> m;
    for (int i=0 ; i<m ; i++){
        cin >> a >> b;
        inv[a]|=(1<<b);
        inv[b]|=(1<<a);
    }

    // pre-prcoess
    for (int i=0 ; i<n ; i++){
        inv[i]|=(1<<i);
        inv[i]=~inv[i];
    }

    // process
    int total=0;
    for (int now_state=1 ; now_state<(1<<n) ; now_state++){
        int low=__lg(now_state&-now_state);
        dp[now_state]=max(dp[now_state^(1<<low)], (char)(dp[now_state&inv[low]]+1));
        total+=dp[now_state];
    }

    // output
    cout << total << "\n";

    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}