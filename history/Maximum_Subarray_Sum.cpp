#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n;
    cin >> n;
 
    vector<long long> v(n+1), dp(n+1); // dp[i] = 必定要選第 i 個時，那 v_1~v_i 可以有的最大的答案是多少？
    for (int i=1 ; i<=n ; i++){
        cin >> v[i];
        dp[i]=max(dp[i-1]+v[i], v[i]);
    }

    for (int i=1 ; i<=n ; i++){
        cerr << dp[i] << " ";
    }
    cerr << "\n";
 
    // output
    long long ma=-2e9;
    for (int i=1 ; i<=n ; i++){
        ma=max(ma, dp[i]);
    }
    cout << ma << "\n";
}