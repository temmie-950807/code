#include <bits/stdc++.h>
#define int long long
const int MAX_SIZE=2e5+5;
using namespace std;
typedef pair<pair<int, int>, int> Data;

int n, l, r, w;
vector<int> v;
vector<Data> ip(MAX_SIZE);
set<pair<int, int>> all_r; // <value, index>

// function
bool cmp(Data A, Data B){
    return A.first<B.first;
}

signed main(void){

    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> l >> r >> w;

        ip[i]={{l, r}, w};
        v.emplace_back(l);
        v.emplace_back(r);
    }

    sort(ip.begin()+1, ip.begin()+1+n);
    // 離散化
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());



    int dp[n+5][v.size()+5];
    memset(dp, 0, sizeof(dp));

    // DP
    all_r.insert({0, 0});
    for (int i=1 ; i<=n ; i++){
        int l_pos=lower_bound(v.begin(), v.end(), ip[i].first.first)-v.begin()+1;
        int r_pos=lower_bound(v.begin(), v.end(), ip[i].first.second)-v.begin()+1;

        int pre=(*prev(all_r.lower_bound({l_pos, 0}))).second; // prev uncover index;

        for (int j=1 ; j<=v.size() ; j++){
            if (j>=r_pos){
                // can put
                dp[i][j]=max(dp[i-1][j], dp[pre][j]+ip[i].second); // no put / put
            }else{
                // can't put
                dp[i][j]=dp[i-1][j];
            }
        }

        // final
        all_r.insert({r_pos, i});
    }

    // for (int i=1 ; i<=n ; i++){
    //     cout << lower_bound(v.begin(), v.end(), ip[i].first.first)-v.begin()+1 << " ";
    //     cout << lower_bound(v.begin(), v.end(), ip[i].first.second)-v.begin()+1 << " ";
    //     cout << ip[i].second << "\n";
    // }
    // for (int i=1 ; i<=n ; i++){
    //     for (int j=1 ; j<=v.size() ; j++){
    //         cout << setw(2) << dp[i][j] << " ";
    //     }   cout << "\n";
    // }

    // output
    cout << dp[n][v.size()];
    return 0;
}