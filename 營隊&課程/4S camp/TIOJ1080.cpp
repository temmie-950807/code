#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;

// declare
int t=1, n, tmp, ans;
int v[MAX_SIZE], BIT[MAX_SIZE];
vector<int> k(MAX_SIZE);

void BIT_update(int idx, int val){
    for (int i=idx ; i<=n ; i+=(i&-i)) BIT[i] += val;
}

int BIT_query(int idx){
    int ret=0;
    for (int i=idx ; i>0 ; i-=(i&-i)) ret += BIT[i];

    return ret;
}

signed main(void){
    fastio;
    
    while (cin >> n && n!=0){
        // init
        ans=0;
        k.clear();

        // input
        for (int i=1 ; i<=n ; i++){
            cin >> tmp;
            BIT[i] = 0;
            v[i]=tmp;
            k.push_back(tmp);
        }

        sort(k.begin(), k.end());
        k.resize(unique(k.begin(), k.end())-k.begin());

        for (int i=1 ; i<=n ; i++){
            tmp = lower_bound(k.begin(), k.end(), v[i])-k.begin()+1;
            ans += i-BIT_query(tmp)-1;
            BIT_update(tmp, 1);
        }

        // output
        cout << "Case #" << t << ": " << ans << "\n";

        // final
        t++;
    }
    
    return 0;
}