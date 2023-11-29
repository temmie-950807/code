#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;

bool check(int l, int r){
    // 確認 [l, r] 是否為可消除的
    stack<char> sta;

    for (int i=l ; i<=r ; i++){
        if (sta.empty()){
            sta.push(s[i]);
        }else if (sta.top()!=s[i]){
            sta.push(s[i]);
        }else{
            sta.pop();
        }
    }

    return sta.empty();
}

void solve1(){

    // input
    cin >> n;
    cin >> s;

    // process
    int ans=0;
    for (int r=0 ; r<n ; r++){
        for (int l=r-1 ; l>=0 ; l-=2){
            ans+=check(l, r);
        }
    }

    // output
    cout << ans << "\n";
}

void solve2(){

    // input
    cin >> n;
    cin >> s;
    s="#@"+s+"!/";

    // process
    int ans=0;
    vector<vector<int>> dp(n+10, vector<int>(n+10));
    for (int gap=2 ; gap<=n ; gap+=2){
        for (int l=2 ; l+gap-1<n+2 ; l++){
            int r=l+gap-1;

            if (gap==2){
                dp[l][r]=(s[l]==s[r]);
            }else{
                dp[l][r]+=dp[l+1][r-1]*(s[l]==s[r]);
                dp[l][r]+=dp[l][r-2]*(s[r-1]==s[r]);
                dp[l][r]+=dp[l+2][r]*(s[l]==s[l+1]);

                if (gap==4 && s[l]==s[l+1] && s[r-1]==s[r]) dp[l][r]--;
                else if (s[l]==s[l+1] && s[r-1]==s[r]) dp[l][r]-=dp[l+2][r-2];
            }

            ans+=dp[l][r];
            cerr << "[" << l << ", " << r << "]: " << dp[l][r] << "\n";
        }
    }

    // output
    cout << ans << "\n";
}

signed main(void){

    solve2();

    return 0;
}