#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF=6e18;
const int MAX_SIZE=5e5+5;
const int MOD=998244353;
int dp[1<<20][MAX_SIZE];

// declare
int n, tmp;
vector<int> v;

void solve1(){
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
    }

    // process
    dp[0][n+1] = 1;
    for (int i = n; i >= 1; i--) {
        int S = 0, cnt = 0;
        for (int j = i; j <= n; j++) {
            if (v[j]) {
                int x = v[j] - 1;
                if ((S & (1 << x)) == 0) cnt++;
                S |= (1 << x);
            }
            if (cnt == j - i + 1) {
                dp[S][i] = dp[(1 << cnt) - 1][j+1];
                for (int T = S; T; T = (T-1) & S) {
                    int val = dp[T][i+cnt];
                    for (int k = 0; k < cnt; k++) {
                        if ((T & (1 << k)) == 0) {
                            int y = (k + j - i + 1) % (j - i + 1);
                            if ((S & (1 << y)) == 0) val = 0;
                        }
                    }
                    dp[S][i] = (dp[S][i] + val) % MOD;
                }
            } else {
                dp[S][i] = dp[0][j+1];
                for (int T = S; T; T = (T-1) & S) {
                    dp[S][i] = (dp[S][i] - dp[T][i]) % MOD;
                }
            }
            if (i > 1) dp[S][i] = (dp[S][i] + dp[S][i+1]) % MOD;
        }
    }

    cout << (dp[(1 << n) - 1][1] + MOD) % MOD << endl;
}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}