#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

// declare
const int MAX_N = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

const int mx[4]={1, 0, -1, 0};
const int my[4]={0, 1, 0, -1};
const string dir="DRUL";

int x, y;
int tile[50][50];
int val[50][50];
bitset<2500> vis;
int now_score=0, final_score=0;
string now_ans="", final_ans="";

bool in(int x, int y){
    return 0<=x && x<50 && 0<=y && y<50;
}

int f(int x, int y){
    return (x-25)*(x-25)+(y-25)*(y-25);
}

mt19937 seed(time(NULL));
int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(seed);
}

void dfs(int x, int y){
    
    // 紀錄移動
    vis[tile[x][y]]=1;

    // 確認答案
    if (now_score>final_score){
        final_score=now_score;
        final_ans=now_ans;
    }

    // 如果超出時間限制就回傳
    if (clock()>=1.98*CLOCKS_PER_SEC) return;

    // 尋找附近四個點哪個可以走，並記錄權重
    vector<pair<int, int>> valid; // <weight, index>
    int pp[4]={0, 0, 0, 0};
    for (int i=0 ; i<4 ; i++){
        if (in(x+mx[i], y+my[i]) && vis[tile[x+mx[i]][y+my[i]]]==0){
            valid.push_back({f(x+mx[i], y+my[i]), i});
        }else{
            pp[i]=1;
        }
    }

    // 增加隨機性
    if (rnd(0, 100)==0){
        int nxt=rnd(0, 3);
        if (pp[nxt]==0){
            pp[nxt]=1;
            now_ans+=dir[nxt];
            now_score+=val[x+mx[nxt]][y+my[nxt]];
            dfs(x+mx[nxt], y+my[nxt]);
            now_score-=val[x+mx[nxt]][y+my[nxt]];
            now_ans.pop_back();
        }
    }

    // 移動四個點
    sort(valid.begin(), valid.end(), greater<>());
    for (auto [weight, index] : valid){
        now_ans+=dir[index];
        now_score+=val[x+mx[index]][y+my[index]];
        dfs(x+mx[index], y+my[index]);
        now_score-=val[x+mx[index]][y+my[index]];
        now_ans.pop_back();
    }

    // 紀錄沒移動過
    vis[tile[x][y]]=0;
    return;

}

void solve1(){

    // input
    cin >> x >> y;
    for (int i=0 ; i<50 ; i++){
        for (int j=0 ; j<50 ; j++){
            cin >> tile[i][j];
        }
    }
    for (int i=0 ; i<50 ; i++){
        for (int j=0 ; j<50 ; j++){
            cin >> val[i][j];
        }
    }

    // process
    dfs(x, y);
    cout << final_ans << "\n";
    cerr << final_score << "\n";
    
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