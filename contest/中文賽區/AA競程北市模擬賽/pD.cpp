#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
int a, b;
vector<pair<int, int>> v;

struct vec{
    int x, y;

    int operator * (vec B){
        return x*B.y-y*B.x;
    }
};
vector<vec> p;

void solve1(){

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back(v[0]);
    for (int i=0 ; i<n ; i++){
        vec ve={v[i+1].first-v[i].first, v[i+1].second-v[i].second};
        p.push_back(ve);
    }

    cerr << "\n\n";
    for (auto g : p){
        cerr << g.x << " " << g.y << "\n";
    }
    cerr << "\n\n";


    // queries
    cin >> q;
    for (int i=0 ; i<q ; i++){
        cin >> a >> b;

        bool x=1, y=0;
        // for ()
        for (int j=0 ; j<n ; j++){
            vec ve={a-v[j].first, b-v[j].second};
            // cerr << ve.x << ", " << ve.y << " | " << ve*p[j] << "\n";
            if (ve*p[j]>0){
                x=0;
            }else if (ve*p[j]==0){
                y=1;
            }
        }

        if (y==1){
            cout << "BOUNDARY\n";
        }else if (x==1){
            cout << "INSIDE\n";
        }else if (x==0){
            cout << "OUTSIDE\n";
        }
        // cerr << "\n\n\n";
    }
}

signed main(void){

    solve1();

    return 0;
}

/*
3
1 1
10 1
5 7
5
1 1
3 4
4 4
4 5
1000000000 1000000000
*/

/*
BOUNDARY
BOUNDARY
INSIDE
INSIDE
OUTSIDE
*/