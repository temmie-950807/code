// 779 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)5e5+5
using namespace std;

vector<int> input(MAX_SIZE), output(MAX_SIZE, 0), cnt(MAX_SIZE, 0);
vector<pair<int, int>> query_L[MAX_SIZE], query_R[MAX_SIZE];

signed main(void){
	fastio;
	
    int n, q, tmp, l, r, x;
    cin >> n >> q;
    
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        input[i] = tmp;
    }

    for (int i=1 ; i<=q ; i++){
        cin >> l >> r >> x;

        // 存output index, 尋找的值
        query_L[l].push_back({i, x});
        query_R[r].push_back({i, x});
    }

    for (int i=1 ; i<=n ; i++){
        for (auto x : query_L[i]){
            output[x.first] -= cnt[x.second];
        }

        cnt[input[i]]++;

        for (auto x : query_R[i]){
            output[x.first] += cnt[x.second];
        }
    }

    for (int i=1 ; i<=q ; i++){
        cout << output[i] << "\n";
    }
    return 0;
}