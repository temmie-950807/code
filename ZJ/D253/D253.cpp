#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int coin[5]={1, 5, 10, 25, 50}, dp[8000]={0};
    dp[0]=1;

    for (int i=0 ; i<5 ; i++){
        for (int j=1 ; j<=7489 ; j++){
            if (j>=coin[i]) dp[j]+=dp[j-coin[i]];
        }
    }

    while (cin >> n){
        cout << dp[n] << "\n";
    }
    return 0;
}