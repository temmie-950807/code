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
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, m, tmp, output_rest=INF, output_v=-INF;
vector<int> a, b, c, v, k, p; // v: 美味程度, k: 飽足感, p: 順序

signed main(void){
	fastio;
	
	cin >> n >> m;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        b.push_back(tmp);
    }
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        c.push_back(tmp);
        v.push_back(abs(a[i]-b[i])+abs(b[i]-c[i])+abs(c[i]-a[i]));
        k.push_back(a[i]+b[i]+c[i]);
    }

    for (int i=0 ; i<n ; i++){
        p.push_back(i);
    }

    // numerate
    do{
        int now_v = 0, now_k = 0, rest = 0;
        for (int i=0 ; i<n ; i++){
            if (now_k + k[p[i]] > m){
                rest++;
                now_k = k[p[i]];
                now_v += (i+1) * v[p[i]];
            }else{
                now_k += k[p[i]];
                now_v += (i+1) * v[p[i]];
            }
        }

        output_rest = min(output_rest, rest);
        output_v = max(output_v, now_v);
    } while (next_permutation(p.begin(), p.end()));
    

    // output
    cout << output_rest << " " << output_v << "\n";
    return 0;
}