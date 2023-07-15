#include <bits/stdc++.h>
#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0). cout.tie(0);
using namespace std;

// declare
const int MAX_SIZE=100005;
const int INF=6e18;
const int MID=50000;

int n, s, tmp;
int counter=0;
vector<int> v;
bitset<MAX_SIZE> dp[100];
// function

void solve1(){
    for (int i=0 ; i<1<<(n-1) ; i++){
        int total=0;
        for (int j=0 ; j<(n-1) ; j++){
            if (i>>j&1){
                total+=v[j];
            }else{
                total-=v[j];
            }
        }

        // check
        if ((s-total)%n==0){
            int now=(s-total)/n;
            // check if now < 0
            if (now<0){
                goto break_point;
            }

            // check if some element < 0
            for (int j=0 ; j<(n-1) ; j++){
                if (i>>j&1){
                    // pass
                }else{
                    if (now-v[j]<0){
                        goto break_point;
                    }
                }
            }

            for (int j=0 ; j<(n-1) ; j++){
                if (i>>j&1){
                    cout << now+v[j] << " ";
                }else{
                    cout << now-v[j] << " ";
                }
            }
            cout << now << "\n";
            return;
        }

        break_point:;
    }

    cout << -1 << "\n";
    return;
}

void solve2(){
    dp[0][0+MID]=1;

    for (int i=1 ; i<=n ; i++){
        dp[i]=(dp[i-1]<<v[i-1])|(dp[i-1]>>v[i-1]);
    }

    // cout << dp[n];
    // for (int j=0 ; j<=n-1 ; j++){
    //     cout << "j: " << j << " | ";
    //     for (int i=-10+MID ; i<10+MID ; i++){
    //         cout << dp[j][i];
    //     }   cout << "\n";
    // }

    // check if have answer
    for (int i=MAX_SIZE ; i>=0 ; i--){
        if (dp[n-1][i] && s-(i-MID)>=0 && (s-(i-MID))%n==0){ // 如果可以組成此數就繼續
            int ans=(s-(i-MID))/n; // 可能的答案
            vector<int> output; // 構造的解

            // check if ans < 0
            if (ans<0){
                goto break_point;
            }
            // cout << "ans: " << ans << "\n";

            // check if  some element < 0
            int now=i;
            for (int j=n-1 ; j>0 ; j--){
                if (counter++==1000000){
                    cout << -1 << "\n";
                    return;
                }

                if (dp[j-1][now-v[j-1]]){ // 如果可以轉移就繼續
                    now-=v[j-1];
                    output.push_back(ans+v[j-1]);
                }else if (dp[j-1][now+v[j-1]]){
                    now+=v[j-1];

                    if (ans-v[j-1]<0){
                        goto break_point;
                    }
                    output.push_back(ans-v[j-1]);
                }else{
                    goto break_point;
                }
            }

            // output
            for (auto x : output){
                cout << x << " ";
            }
            cout << ans << "\n";
            return;
        }

        break_point:;
    }

    // output
    cout << -1 << "\n";
    return;
}

signed main(){
    
    // input
    cin >> n >> s;
    for (int i=0 ; i<n-1 ; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    if (n<=20){
        solve1();
    }else{
        solve2();
    }

    return 0;
}