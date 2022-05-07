#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int s[101]={0}, v[101]={0}; // size, value
    int dp[101][101];

    while (cin >> n){
        // input
        for (int i=1 ; i<=n ; i++){
            cin >> s[i] >> v[i];
        }

        // process
        for (int i=0 ; i<=n ; i++){
            for (int j=0 ; j<=100 ; j++){
                if (i==0 || j==0) dp[i][j]=0;
                else if (j-s[i]<0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j], dp[i-1][j-s[i]]+v[i]);
            }
        }

        // output
        cout << dp[n][100] << "\n";
    }
    return 0;
}