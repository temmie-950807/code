#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=5e5+5;
const int INF=2e18;

int a, b, x, y, n, m;

int qp(int b, int p, int m){
    int ret=1;
    for ( ; p ; p>>=1){
        if (p&1) ret=ret*b%m;
        b=b*b%m;
    }
    return ret;
}

void solve1(){

    // input
    cin >> a >> b >> x >> y >> n >> m;

    // process
    cout << qp(a, x, n) << " " << 0 << "\n";
}

signed main(void){
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}