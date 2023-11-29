#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

int n, tmp;
vector<vector<int>> v;
map<vector<vector<int>>, int> ss;


int det(vector<vector<int>> a){

    int N=a.size();

    if (N==1){
        return a[0][0];
    }else if (ss.find(a)!=ss.end()){
        return ss[a];
    }else{
        int now=1;
        int total=0;

        for (int i=0 ; i<N ; i++){
            vector<vector<int>> p(N-1);

            for (int j=1 ; j<N ; j++){
                for (int k=0 ; k<N ; k++){
                    if (k!=i){
                        p[j-1].push_back(a[j][k]);
                    }
                }
            }

            total+=now*a[0][i]*det(p);
            now*=-1;
        }

        ss[a]=total;
        return total;
    }
}

void solve1(){
    
    // iunput
    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin >> tmp;
            v[i][j]=tmp;
        }
    }

    // process
    cout << det(v) << "\n";

    // for (auto x : ss){
    //     for (auto y : x.first){
    //         for (auto z : y){
    //             cerr << z << " ";
    //         }
    //         cerr << "\n";
    //     }
    //     cerr << "val = " << x.second << "\n\n";
    // }
}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}