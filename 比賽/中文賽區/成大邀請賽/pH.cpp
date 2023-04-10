#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
using namespace std;

// declare
const int MAX_SIZE = 2e5+5;

int n, m, k, tmp;
vector<vector<int>> dp;
vector<int> v(1), p, left_pos(MAX_SIZE);

void solve1(){
    // input
    cin >> n >> m >> k;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    dp.resize(2, vector<int>(n+1, 0));
    p.resize(v.size());
    partial_sum(v.begin(), v.end(), p.begin());

    // process
    for (int i=1 ; i<=n ; i++){
        int ll=1, rr=i+1;
        while (ll<rr){
            int mid=ll+(rr-ll)/2;
            if (p[i]-p[mid-1]<=k){
                rr=mid;
            }else{
                ll=mid+1;
            }
        }

        left_pos[i]=ll-1;
    }

    // preview
    // cout << "." << endl;
    // for (int i=0 ; i<=n ; i++){
    //     cout << setw(2) << v[i] << " ";
    // }   cout << endl;
    // for (int i=0 ; i<=n ; i++){
    //     cout << setw(2) << left_pos[i] << " ";
    // }   cout << endl << endl;

    // dp
    int ans=0;
    for (int i=1 ; i<=m ; i++){
        for (int j=1 ; j<=n ; j++){
            dp[i&1][j]=max({dp[1&i][j-1], dp[1-(i&1)][left_pos[j]]+(p[j]-p[left_pos[j]]), dp[1-(i&1)][j]});
            // cout << dp[i&1][j] << " ";
            ans=max(ans, dp[i&1][j]);
        }
        // cout << endl;
    }
    // cout << endl;

    // output
    cout << ans << endl;
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