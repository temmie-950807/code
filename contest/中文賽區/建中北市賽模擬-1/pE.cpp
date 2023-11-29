#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=1e5+5;
const int INF=2e18;

int n, q;
int a, b, k;
int tmp;
vector<int> v(1);
int l, r;

void solve1(){
    // queries
    for (int i=0 ; i<q ; i++){
        cin >> l >> r;

        int ans=0;
        for (int jj=l ; jj<=r ; jj++){
            for (int kk=jj+1 ; kk<=r ; kk++){
                if ((v[jj]^v[kk]^a)+(v[jj]^v[kk]^b)>=k){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}

void solve2(){

    // pre-process
    vector<vector<int>> dp(3005, vector<int>(3005));
    for (int i=1 ; i<=n ; i++){
        for (int j=i+1 ; j<=n ; j++){
            dp[i][j]+=((v[i]^v[j]^a)+(v[i]^v[j]^b)>=k);
        }
    }

    for (int i=1 ; i<n ; i++){
        for (int j=1 ; j+i<=n ; j++){
            if (i==1){
                dp[j][j+i]+=dp[j][j]+dp[j+1][j+1];
            }else{
                dp[j][j+i]+=dp[j][j+i-1] + dp[j+1][j+i] - dp[j+1][j+i-1];
            }
        }
    }

    // queries
    for (int i=0 ; i<q ; i++){
        cin >> l >> r;
        cout << dp[l][r] << "\n";
    }
}


void solve3(){
    // pre-process
    vector<vector<pair<int, int>>> qq(MAX_N);
    vector<vector<int>> cnt(2048);
    vector<int> ans(MAX_N, 0);

    for (int i=0 ; i<q ; i++){
        cin >> l >> r;
        qq[r].push_back({l, i});
    }

    for (int i=1 ; i<=n ; i++){
        int total=0;

        for (int j=0 ; j<2048 ; j++){
            if (((j^v[i]^a)+(j^v[i]^b))>=k){

                for (auto x : qq[i]){
                    if (cnt[j].size()){
                        cerr << x.first << " " << i << " | ";
                        for (auto x : cnt[j]){
                            cerr << x << " ";
                        }
                        cerr << "\n";
                        ans[x.second]+=cnt[j].size()-(upper_bound(cnt[j].begin(), cnt[j].end(), x.first)-cnt[j].begin());
                    }
                }
            }
        }

        cnt[v[i]].push_back(i);
    }

    // queries
    for (int i=0 ; i<q ; i++){
        cout << ans[i] << "\n";
    }
    
}

signed main(void){
    int t=1;
    while (t--){
        // input
        cin >> n >> q;
        cin >> a >> b >> k;
        for (int i=0 ; i<n ; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        solve3();
        return 0;
        if (n<=3000){
            solve2();
        }else{
            solve3();
        }
    }
    return 0;
}