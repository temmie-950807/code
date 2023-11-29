#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=2e5+5;
const int INF=2e18;

int n, q, tmp;
int cmd, a, b;
vector<int> h(1), w(1);
vector<int> l(MAX_N), r(MAX_N);
vector<int> BIT(MAX_N);

void update(int pos, int val){
    for (int i=pos ; i<MAX_N ; i+=i&-i){
        BIT[i]+=val;
    }
}

int query(int pos){
    if (pos<=0) return 0;
    int ret=0;
    for (int i=pos ; i>0 ; i-=i&-i){
        ret+=BIT[i];
    }
    return ret;
}

void solve1(){

    // input
    cin >> n >> q;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        h.push_back(tmp);
    }
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        w.push_back(tmp);
    }

    // process
    {
        stack<pair<int, int>> sta;
        for (int i=1 ; i<=n ; i++){
            while (sta.size() && sta.top().first<=h[i]){
                sta.pop();
            }

            if (sta.empty()) l[i]=1;
            else l[i]=sta.top().second+1;
            sta.push({h[i], i});
        }
    }
    {
        reverse(h.begin()+1, h.end());
        stack<pair<int, int>> sta;
        for (int i=1 ; i<=n ; i++){
            while (sta.size() && sta.top().first<=h[i]){
                sta.pop();
            }

            if (sta.empty()) r[n-i+1]=n;
            else r[n-i+1]=sta.top().second-1;
            sta.push({h[i], n-i+1});
        }
        reverse(h.begin()+1, h.end());
    }
    for (int i=1 ; i<=n ; i++){
        update(i, w[i]);
    }

    // queries
    for (int i=0 ; i<q ; i++){
        cin >> cmd;

        if (cmd==1){
            // update w[i] to x
            cin >> a >> b;
            update(a, b-w[a]);
            w[a]=b;

        }else{
            // query x;
            cin >> a;
            cout << query(r[a])-query(l[a]-1) << "\n";

        }
    }

}

signed main(void){
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}

/*
5 7
3 2 2 5 6
1 2 4 8 16
2 3
2 1
2 5
1 2 100
2 2
2 4
2 5
*/

/*
6
7
31
104
113
129
*/

/*
5 7
3 2 7 5 6
1 2 4 8 16
*/