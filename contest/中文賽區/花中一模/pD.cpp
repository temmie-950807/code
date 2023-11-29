#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=5e5;

int q, cmd, x;
int people_start=0, people_end=0, now_mask=0;
queue<pair<int, int>> ss; // <人數, 差值>

void solve1(){

    // queries
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> cmd >> x;

        if (cmd==1){
            // get mask
            now_mask-=x;

        }else if (cmd==2){
            // x people out
            people_start+=x;
            while (ss.size() && ss.front().first<=people_start){
                ss.pop();
            }

        }else if (cmd==3){
            // x people in
            people_end+=x;
            ss.push({people_end, now_mask});

        }

        if (ss.size()){
            cout << ss.front().second-now_mask << "\n";
        }else{
            cout << 0 << "\n";
        }
    }
}

signed main(void){

    fastio;

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}

/*
3
3 5
1 4
1 9
*/

/*
7
3 1
1 6
3 1
3 1
1 2
2 1
1 1
*/

/*
8
3 1000000
1 1000000
2 999999
3 1000000
1 1000000
2 999999
3 1000000
1 1000000
*/