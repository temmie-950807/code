#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAX_N = 1e6+5;

int n;
vector<int> dp(1e6+5); // dp[i] = 如果要湊出 i 點，請問有多少種排列方式

int main(){

    // input
    cin >> n;

    // process
    dp[0]=1; // 如果要得到 0 點怎麼辦？都不要投，因此有 1 種方法。
    for (int i=1 ; i<=n ; i++){ // 走第 i 階的樓梯
        for (int j=1 ; j<=6 ; j++){ // 枚舉走的階數
            if (i-j>=0){ // 確認目前的階數能不能被轉移
                dp[i]+=dp[i-j];
                dp[i]%=MOD;
            }
        }
    }

    // output
    cout << dp[n] << "\n";

    return 0;
}