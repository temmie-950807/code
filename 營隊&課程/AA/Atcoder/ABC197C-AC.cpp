// 0.15 s
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
    
    int n, tmp, output=2e18;
    int OR=0, XOR=0;
    vector<int> input(20);

    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        input[i] = tmp;
    }

    for (int i=0 ; i<(1<<n) ; i++){ // 窮舉0~(2^n)-1
        // init
        OR  = 0; // 由於OR的性質, 一開始為0不會有影響
        XOR = 0;

        // process
        for (int j=1 ; j<=n ; j++){
            OR |= input[j-1];
            if ((i>>j)&1){ // 取得所有位元的位置
                XOR ^= OR; // 分隔
                OR = 0; // reset
            }
        }

        // record
        XOR ^= OR; // 確保如果最後不是1的話 可以儲存起來
        output = min(output, XOR);
    }

    cout << output << "\n";
    return 0;
}