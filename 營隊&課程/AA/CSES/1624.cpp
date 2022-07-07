// 0.01 s
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

signed main(void){
	fastio;
    
    int output=0;
    bool check;
    vector<string> input;
    vector<int> place={0, 1, 2, 3, 4, 5, 6, 7};
    string s;

    for (int i=0 ; i<8 ; i++){
        cin >> s;
        input.push_back(s);
    }

    do{
        check = 1;
        for (int i=0 ; i<8 ; i++){
            for (int j=0 ; j<8 ; j++){
                if (i==j) continue;
                else if (input[i][place[i]]!='*' && (abs(i-j)!=abs(place[i]-place[j]))){
                }else{
                    check = 0;
                }
            }
        }
        if (check) output++;
    }while(next_permutation(place.begin(), place.end()));

    cout << output << "\n";
    return 0;
}