// 46 ms
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

signed main(void){
	fastio;
	
    int n, m, tmp, output=0;
    vector<int> row[MAX_SIZE], column[MAX_SIZE];

    cin >> n >> m;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            cin >> tmp;
            row[tmp].push_back(i);    // 在tmp加入此行(i)數
            column[tmp].push_back(j); // 在tmp加入此列(j)數
        }
    }

    for (int i=1 ; i<MAX_SIZE ; i++){ // 遍歷所有值(c)
        int s=0;
        sort(row[i].begin(), row[i].end());     // 針對每個值先排序(依照行數)
        for (int j=0 ; j<row[i].size() ; j++){
            output += j*row[i][j]-s;            // j*row[i][j]   = 1~row[i][j] 所有的距離
            s += row[i][j];                     // s             = 前面所有的距離
                                                // j*row[i][j]-s = 為row[i][j]跟前面的點的所有距離
        }

        s=0;
        sort(column[i].begin(), column[i].end());
        for (int j=0 ; j<column[i].size() ; j++){
            output += j*column[i][j]-s;
            s += column[i][j];
        }
    }

    cout << output << "\n";
    return 0;
}