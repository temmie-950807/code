#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX_N=1e5+5;

int n;
vector<int> cnt(MAX_N), dp(MAX_N), suf(MAX_N);

/*
cnt[i] = i 出現多少次
dp[i]  = 
suf[i] = i 後面出現幾次
*/

// fast IO
inline char readchar(){
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}
inline int nextint(){
    int x = 0, c = readchar(), neg = false;
    while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
    if(c == '-') neg = true, c = readchar();
    while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
    if(neg) x = -x;
    return x; // returns 0 if EOF
}

void solve1(){

    // init
    fill(cnt.begin(), cnt.end(), 0);
    fill(dp.begin(), dp.end(), 0);
    fill(suf.begin(), suf.end(), 0);

    // input
    n=nextint();
    for (int i=0 ; i<n ; i++){
        cnt[nextint()]++;
    }
    for (int i=MAX_N-1 ; i>0 ; i--){
        suf[i-1]+=suf[i]+cnt[i];
    }
    for (int i=0 ; i<20 ; i++){
        cerr << cnt[i] << " ";
    }
    cerr << "\n";
    for (int i=0 ; i<20 ; i++){
        cerr << suf[i] << " ";
    }
    cerr << "\n";

    // process
    int ans=0;
    for (int i=100000 ; i>=1 ; i--){
        for (int j=i ; j<=100000 ; j+=i){
            if (i!=j) dp[i]-=dp[j];

            
        }
    }

    // output
    cout << ans << "\n";
    return;
}

signed main(void){
    fastio;

    int t=1;
    t=nextint();
    while (t--){
        solve1();
    }
    return 0;
}