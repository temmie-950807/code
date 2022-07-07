// 186 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
	
    int n, q, tmp;
    cin >> n;
    int add=0, alive=n; // 總共被加上的數量
    vector<int> input, output(n, 0);

    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        input.push_back(tmp);
    }

    cin >> q;
    for (int i=1 ; i<=q ; i++){ // i = 回合數
        cin >> tmp;
        tmp--;

        input[tmp] -= (alive-1)*i; // 扣錢

        if (input[tmp]+add<0){
            // 把被加上的以及原本的金錢扣掉, 減去人數
            output[tmp] = input[tmp]+add;
            alive--;
        }else{
            input[tmp] -= i;
        }

        add += i; // 全部被加上的數量
    }
    
    for (int i=0 ; i<n ; i++){
        if (output[i]==0){
            cout << input[i]+add << " ";  // 目前存活的, 因為input沒有被加上, 所以還要加上add
        }else{
            cout << output[i] << " ";     // 已經死亡的, 不用處理任何事
        }
    }cout << "\n";

    return 0;
}

// 2
// 10 0
// 6
// 1 1 1 1 2 2

// 11 -1