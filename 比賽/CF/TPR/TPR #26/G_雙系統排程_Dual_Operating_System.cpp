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
int n, m, a, b, x, y, tmp, e, c, output=-INF;
vector<int> A, B, v;
int p=0;
string now;

signed main(void){
	// fastio;
	
	cin >> n >> m >> a >> b >> x >> y;
    for (int i=0 ; i<a; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i=0 ; i<b; i++){
        cin >> tmp;
        B.push_back(tmp);
    }
    for (int i=0 ; i<m; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    while (p < (1<<m)){
        now = "windows";
        e = 0;
        c = 0;
        tmp = p;
        cout << p << "\n";
        while (c<m){
            if (tmp&1){
                e -= y;
                if (now=="windows") now="ubuntu";
                if (now=="ubuntu") now="windows";
            }
            
            if (now=="windows" && binary_search(A.begin(), A.end(),v[c])){
                e+=x;
            }
            if (now=="ubuntu" && binary_search(B.begin(), B.end(),v[c])) {
                e+=x;
            }

            // cout << e << " ";

            tmp >>= 1;
            c++;
        }

        cout << "\ne: " << e << "\n";

        p++;
        output = max(output, e);
    }

    // output
    cout << output << "\n";
    return 0;
}