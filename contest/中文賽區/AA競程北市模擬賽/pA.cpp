#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=3e5;
const int INF=8e18+5;

int r, c, n;
int x, y, t;
char d, a;

char dir[4]={'R', 'L', 'D', 'U'};
int mx[4]={0, 0, 1, -1};
int my[4]={1, -1, 0, 0};

bool in(int x, int y){
    return 0<=x && x<r && 0<=y && y<c;
}

void solve1(){

    // input
    cin >> r >> c;
    set<tuple<int, int, int, int, int, char>> store; // <time, idx, dir, x, y, fill>
    set<tuple<int, int, int, int, char>> now; // <idx, dir, x, y, fill>
    set<tuple<int, int, int, int, char>> nxt; // <idx, dir, x, y, fill>
    vector<string> ans(r, string(c, '#'));

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> x >> y >> t >> d >> a;
        x--;
        y--;
        int way=4;
        for (int i=0 ; i<4 ; i++){
            if (d==dir[i]) way=i;
        }

        store.insert({t, i, way, x, y, a});
    }

    int now_time=1;
    while (store.size() || now.size()){

        if (now.size()==0){
            now_time=get<0>(*store.begin());
        }
        while (store.size() && get<0>(*store.begin())==now_time){
            auto &[a, b, c, d, e, f]=*store.begin();
            now.insert({b, c, d, e, f});
            store.erase(store.begin());
        }
        nxt.clear();

        for (auto &[idx, dir, x, y, fill] : now){
            if (!(in(x, y))) continue;
            if (ans[x][y]!='#') continue;
            ans[x][y]=fill;
            int tmp_x=x+mx[dir];
            int tmp_y=y+my[dir];

            nxt.insert({idx, dir, tmp_x, tmp_y, fill});
        }

        swap(now, nxt);
        now_time++;
    }

    // output
    for (auto x : ans){
        cout << x << "\n";
    }
    
}

signed main(void){

    solve1();

    return 0;
}

/*
4 5 6
1 4 3 L A
1 1 4 R B
1 3 10 D C
2 5 100 L Z
4 5 98 U A
4 1 1000000000 D G
*/

/*
BAAA#
ZZZZZ
####A
G###A
*/

/*
5 4 7
1 2 1 D X
1 3 1 D Y

1 1 1 R A
3 1 1 R B
5 1 1 R C

2 4 1 L D
4 4 1 L E
*/

/*
5 5 3
3 1 1 R A
4 3 1 U B
1 5 1 D C
*/