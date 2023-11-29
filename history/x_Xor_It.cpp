#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

bool debug_mode=true;
#define cerr if(debug_mode) cerr
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T, typename ...U> void _do(T x, U ...y){cerr << x << ", "; _do(y...);}
#define dbg(...) cerr << #__VA_ARGS__ << " = "; _do(__VA_ARGS__);

const int MAX_N=2e5+5;
const int INF=2e18;

int n, x, tmp;
int N=30, id=1;
vector<int> v;
vector<vector<int>> trie;

void Insert(int n){
    int now=0;

    for (int i=N ; i>=0 ; i--){
        int b=((n>>i)&1);
        if (trie[now][b]==0) trie[now][b]=id++;
        now=trie[now][b];
    }

}

int Query(int n){
    int now=0, ans=0;

    for (int i=N ; i>=0 ; i--){
        int b1=((n>>i)&1);
        int b2=((x>>i)&1);
        if (trie[now][b1^b2^1]!=0){
            now=trie[now][b1^b2^1];
            ans+=(1<<i);
        }else{
            now=trie[now][b1^b2];
        }
    }

    return ans;
}

void solve1(){

    // init
    cin >> n >> x;
    id=1;
    v.clear();
    trie.clear();
    trie.resize(30*n, vector<int>(2));

    // process
    int ma=0, now=0;
    Insert(now);
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        now^=tmp;
        Insert(now);
        dbg(now, Query(now));
        ma=max(ma, Query(now));
    }

    // output
    cout << ma << "\n";
}

signed main(){

    int t=1;
    cin >> t;
    while (t--){
        solve1();
    }

    return 0;
}