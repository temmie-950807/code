// sparse table
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input, add=1;
    int q, k, r, l;
    cin >> n;
    int h=floor(log2(n));
    vector<int> ST[n];

    for (int i=0 ; i<n ; i++){
        cin >> input;
        ST[0].push_back(input);
    }

    for (int i=1 ; i<=h ; i++){
        for (int j=0 ; j+add<ST[i-1].size() ; j++){
            ST[i].push_back(max(ST[i-1][j], ST[i-1][j+add]));
        }
        add*=2;
    }

    cin >> q;
    // query
    for (int i=0 ; i<q ; i++){
        cin >> l >> r;
        l--;
        r--;
        k=floor(log2(r-l+1)); // [l, r]的長度
        cout << max(ST[k][l], ST[k][r-(int)pow(2, k)+1]) << "\n";
    }
    return 0;
}