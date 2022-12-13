#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#if !LOCAL
#define endl "\n"
#endif
using namespace std;

// declare
const int MAX_SIZE = 1<<19;

int t=1, n, tmp;
int v[MAX_SIZE], vis[MAX_SIZE], lpf[MAX_SIZE];
vector<int> prime;

// function
void prime_init(){
    for (int i=2 ; i<MAX_SIZE ; i++){
        if (!lpf[i]){
            prime.push_back(i);
            for (int j=i ; j<MAX_SIZE ; j+=i){
                if (!lpf[j]) lpf[j]=i;
            }
        }
    }
}

void solve(){
    // init
    t++;
    set<int> s;

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> v[i];
    }

    for (int i=0 ; i<n ; i++){
        int now=v[i];

        for (int x : prime){
            if (x*x>now) break;
            if (now%x==0){
                if (vis[x]==t){
                    cout << "YES" << endl;
                    return;
                }
                vis[x]=t;
                now/=x;
                while (now%x==0) now/=x;
            }
        }

        if (now!=1){
            if (now<MAX_SIZE){
                if (vis[now]==t){
                    cout << "YES" << endl;
                    return;
                }
                vis[now]=t;
            }else{
                if (!s.insert(now).second){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
    return;
}

signed main(void){
    fastio;

    prime_init();
    
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}