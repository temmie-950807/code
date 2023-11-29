#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=2e18;
int n, k, l;
int a, b;
queue<pair<int, int>> qq; // <pos, price>

void solve1(){

    // input
    cin >> n >> k >> l;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        if (qq.size() && a-qq.back().first>k){
            cout << -1 << "\n";
            return;
        }
        qq.push({a, b});
    }
    qq.push({l, 0});

    // process
    int now_pos=0, now_oil=k, cost=0;
    int now_price=INF;
    deque<pair<int, int>> sta; // <pos, price>
    while (now_pos<l){
        while (qq.size() && qq.front().first<=now_pos+k){
            // 確認還有「可以到的加油站」、「遞增的備案」
            while (sta.size() && sta.back().second>=qq.front().second){
                sta.pop_back();
            }
            sta.push_back(qq.front());
            qq.pop();
        }

        cerr << "pos: " << now_pos << " cost: " << cost << "\n";

        if (now_price<sta.front().second){
            // 現在的油價比所有能到的地方都便宜
            cost+=(k-now_oil)*now_price;
            int dis=sta.front().first-now_pos;
            now_oil-=dis;
            sta.pop_front();
        }else{
            // 可以去更便宜的地方買油
            cost+=(k-now_oil)*now_price;
            int dis=sta.front().first-now_pos;
            now_oil-=dis;
            sta.pop_front();
        }
    }

    // output
    cout << cost << "\n";
}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}