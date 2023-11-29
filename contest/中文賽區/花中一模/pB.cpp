#include <bits/stdc++.h>
#define int long long
#define fastio cin.tie(0), ios::sync_with_stdio(0);
using namespace std;

const int INF=8e18;
const int MAX_N=3e5;

int n, tmp;
vector<int> a(1), b(1);
vector<int> awin(MAX_N), bwin(MAX_N);

void solve1(){

    // input
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i=1 ; i<=n ; i++){
        cin >> tmp;
        b.push_back(tmp);
    }

    // process
    for (int i=1 ; i<=n ; i++){
        awin[i]=awin[i-1];
        bwin[i]=bwin[i-1];

        if (a[i]>b[i]){
            awin[i]++;
        }else if (b[i]>a[i]){
            bwin[i]++;
        }
    }

    // queries
    for (int i=1 ; i<=n ; i++){
        int l=min(a[i], b[i]);
        int r=max(a[i], b[i]);

        int aa=awin[r]-awin[l-1];
        int bb=bwin[r]-bwin[l-1];

        // output
        if (aa==bb){
            cout << 0;
        }else if (aa>bb){
            cout << 1;
        }else{
            cout << 2;
        }
    }
}

signed main(void){

    fastio;

    int t=1;
    while (t--){
        solve1();
    }
    

    return 0;
}

/*
3
1 2 3
3 1 2
*/

/*
101
*/

/*
8
2 2 2 1 5 6 1 4
3 1 2 4 3 1 8 1
*/

/*
10120112
*/