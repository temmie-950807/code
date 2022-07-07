// 60 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
	
    bool flip=0;
    int n, q, t, a, b;
    string s;

    cin >> n >> s >> q;
    for (int i=0 ; i<q ; i++){
        cin >> t >> a >> b;

        if (t==2){
            flip = abs(flip-1);
        }else{
            if (flip==1){
                if (a<=n) a+=n-1;
                else a-=n+1;

                if (b<=n) b+=n-1;
                else b-=n+1;
            }else{
                a--;
                b--;
            }

            s[a]^=s[b];
            s[b]^=s[a];
            s[a]^=s[b];
        }
    }

    if (flip==1){
        for (int i=0 ; i<n ; i++){
            s[i]^=s[n+i];
            s[n+i]^=s[i];
            s[i]^=s[n+i];
        }
    }
    cout << s << "\n";
    
    return 0;
}