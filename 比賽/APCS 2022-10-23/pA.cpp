#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e18;

// 宣告
int mi=INF, ma=-INF;
int n, a, b;
vector<pair<int, int>> v;

signed main(void){
    // 輸入
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    // 尋找最大 & 最小值
    for (int i=0 ; i<n-1 ; i++){
        mi=min(mi, abs(v[i].first-v[i+1].first)+abs(v[i].second-v[i+1].second));
        ma=max(ma, abs(v[i].first-v[i+1].first)+abs(v[i].second-v[i+1].second));
    }

    // 輸出
    cout << ma << " " << mi << "\n";
    
    return 0;
}