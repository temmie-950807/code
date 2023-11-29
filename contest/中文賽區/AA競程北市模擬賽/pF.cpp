#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=5e5+5;

int n, k, tmp;
vector<int> v, idx(MAX_N);

void solve1(){

    // input
    cin >> n >> k;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.push_back(tmp);
        idx[tmp]=i;
    }

    // process
    for (int i=n ; i>=1 ; i--){

        for (int j=idx[i] ; j>=1 ; j--){
            if (abs(v[j]-v[j-1])<=k){
                swap(idx[v[j]], idx[v[j-1]]);
                swap(v[j], v[j-1]);
            }else{
                break;
            }
        }

        // output
        // cout << "i: " << i << "\n";
        for (int i=0 ; i<n ; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        // for (int i=1 ; i<=n ; i++){
        //     cout << idx[i] << " ";
        // }
        // cout << "\n\n";
    }

    for (int i=0 ; i<n ; i++){
        cout << v[i] << " ";
    }
}

signed main(void){

    solve1();

    return 0;
}