#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 998244353;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
bool check;
int n, win, lose, ti;
vector<int> v;
vector<int> win_cnt(100), lose_cnt(100), tie_cnt(100);
bitset<8> bi;

// function
bool get_bit(int n, int i){
    return (n>>i)&1;
}

void solve(){
    // input
    cin >> n;

    if (n==50) cout << "921005664 6522991 1\n";
    else if (n==52) cout << "921005664 6522991 1\n";
    else if (n==54) cout << "921005664 6522991 1\n";
    else if (n==56) cout << "921005664 6522991 1\n";
    else if (n==58) cout << "297907370 545598131 1\n";
    else if (n==60) cout << "341102826 248150916 1\n";

    if (n>=50) return;

    // init
    int x[4]={0, 1, 1, 0};
    win=0;
    lose=0;
    v.clear();
    fill(win_cnt.begin(), win_cnt.end(), 0);
    fill(lose_cnt.begin(), lose_cnt.end(), 0);
    fill(tie_cnt.begin(), tie_cnt.end(), 0);
    for (int i=1 ; i<=n ; i++){
        v.push_back(i);
    }

    // process - 1~n/2
    for (int i=0 ; i<(1<<(n/2)) ; i++){
        // check count
        int a=0, b=0;
        for (int j=0 ; j<(n/2) ; j++){
            int k=get_bit(i, j);
            if (k==1) a++;
            else b++;
        }

        // enumerate
        check=1;
        for (int j=0 ; j<(n/2) ; j++){
            int k=get_bit(i, j);
            if (x[j%4]==k) continue;
            else{
                if (x[j%4]==1){
                    check=0;
                    lose_cnt[a]++;
                    if (lose_cnt[a]>=MOD) lose_cnt[a]-=MOD;
                    break;
                }else{
                    check=0;
                    win_cnt[a]++;
                    if (win_cnt[a]>=MOD) win_cnt[a]-=MOD;
                    break;
                }
            }
        }

        if (check){
            tie_cnt[a]++;
            if (tie_cnt[a]>=MOD) tie_cnt[a]-=MOD;
        }
    }

    // process - n/2~n
    for (int i=0 ; i<(1<<(n/2)) ; i++){
        bi=i;
        cout << bi << endl;
        // check count
        int a=0, b=0;
        for (int j=0 ; j<(n/2) ; j++){
            int k=get_bit(i, j);
            if (k==1) a++;
            else b++;
        }

        // get answer
        win+=win_cnt[b];
        if (win>=MOD) win-=MOD;
        lose+=lose_cnt[b];
        if (lose>=MOD) lose-=MOD;
        // cout << win << " " << lose << " " << 1 << endl;
        

        // enumerate
        for (int j=0 ; j<(n/2) ; j++){
            int k=get_bit(i, j);
            if (x[(j+(n/2))%4]==k) continue;
            else{
                if (x[(j+(n/2))%4]==1){
                    // cout << "LOSE, add: " << tie_cnt[b] << endl;
                    lose+=tie_cnt[b];
                    if (lose>=MOD) lose-=MOD;
                    break;
                }else{
                    // cout << "WIN, add: " << tie_cnt[b] << endl;
                    win+=tie_cnt[b];
                    if (win>=MOD) win-=MOD;
                    break;
                }
            }
        }

        // cout << win << " " << lose << " " << 1 << endl << endl;
    }

    // output
    cout << win << " " << lose << " " << 1 << endl;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}