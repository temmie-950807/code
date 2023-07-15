#include <bits/stdc++.h>
#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int INF=6e18;
const int MAX_SIZE=5e5+5;

// declare
int x, y, node_val, tree_idx, x_idx;
vector<int> ans, tree(MAX_SIZE);

void solve1(){
    cin >> x >> y;

    if (y%2==1){
        cout << ":(" << "\n";
        return;
    }

    // enumerate
    for (int i=0 ; i<(1<<y) ; i++){
        // init
        ans.clear();
        node_val=1;
        tree_idx=0;
        x_idx=0;
        fill(tree.begin(), tree.begin()+1000, 0);

        for (int j=0 ; j<y ; j++){
            ans.push_back((i>>j)&1);
        }
        if (ans[0]==0 || ans[x-1]==0 || ans[y-1]==0) continue;

        for (auto x : ans){
            cout << x << " ";
        }   cout << "\n";

        for (int j=1 ; node_val<=y ; j++){
            // j 會跑遍整顆樹
            if (tree[j/2]==-1){
                continue;
            }else{
                if (ans[node_val]==1){
                    tree[j]=node_val;
                    if (node_val==x){
                        x_idx=j;
                    }
                }else{
                    tree[j]=-1;
                }

                node_val++;
            }
        }

        // check answer
        if (tree[x_idx*2]==y){
            for (auto x : ans){
                cout << (x==1 ? "1" : "null") << " ";
            }   cout << "\n";
            return;
            // cout << "OH YES" << endl;
        }

        for (int i=0 ; i<20 ; i++){
            cout << tree[i] << " ";
        }   cout << "\n";
        cout << "\n";
    }
}

void solve2(){
    // input
    cin >> x >> y;

    if (y&1==1){
        cout << ":(\n";
        return;
    }else{
        ans.push_back(0);

        for (int i=0 ; i<x ; i++){
            ans.push_back(1);
        }
        int max_can_delete=x-(1<<__lg(x));
        // cout << max_can_delete << endl;

        int need_move=2*x-y;
        // cout << need_move << endl;
        
        for (int i=(1<<__lg(x)) ; i<x && need_move>0 ; i++){
            ans[i]=0;
            need_move-=2;
        }

        if (need_move>0){
            cout << ":(\n";
            return;
        }else{
            while (ans.size()<y){
                ans.push_back(1);
            }
        }
    }

    // output
    cout << "[";
    for (int i=1 ; i<ans.size() ; i++){
        cout << (ans[i]==1 ? "1" : "null");
        if (i==ans.size()-1) cout << "]";
        else cout << ",";
    }
}

signed main(){
    fastio

    int t=1;
    while (t--){
        solve2();
    }

    return 0;
}