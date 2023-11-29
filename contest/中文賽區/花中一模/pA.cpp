#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=5e5;
const int MOD=1e9+7;

int n, tmp;

void solve1(){

    // init
    int total=0;

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        total+=tmp;
        total%=MOD;
    }

    // output
    cout << total << "\n";
}

signed main(void){

    fastio;

    int t=1;
    cin >> t;
    while (t--){
        solve1();
    }
    

    return 0;
}