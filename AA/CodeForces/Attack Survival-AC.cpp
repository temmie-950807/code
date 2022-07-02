// 23 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
signed main(void){
	fastio;
	
    int n, k, q;
    int tmp;
    cin >> n >> k >> q;
    vector<int> score(n, 0);

    for (int i=0 ; i<q ; i++){
        cin >> tmp;
        score[tmp-1]++;
    }

    for (int i=0 ; i<n ; i++){
        if (q-score[i]<k){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}