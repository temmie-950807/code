#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int t, n, a, b, ans;
vector<int> G[MAX_SIZE];


int dfs(int now, int p){ // now: 目前的節點, p: 確保只會朝一個方向DFS
    bool check = 1;      // 檢查其他子樹不會超過n/2
    int cnt=0;           // 計算子樹的節點數量(會遞迴上去)

    for (auto x : G[now]){
        if (x==p) continue;
        int r = dfs(x, now);
        if (r>n/2) check = 0;
        cnt += r;
    }

    if ((n-1-cnt)>n/2) check = 0; // 檢查剩餘的部分計算起來
    if (check) ans = min(ans, now);

    return cnt+1; 
}

signed main(void){
	fastio;
	
	cin >> t;
	while (t--){
        // init
		fill(G, G+MAX_SIZE, vector<int>());
        
	    // input
        cin >> n;
        for (int i=0 ; i<n-1 ; i++){
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        ans = MAX_SIZE;
        dfs(0, 0);
        
        cout << ans << "\n";
	}
    return 0;
}