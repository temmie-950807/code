#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=5e5+5;
const int INF=2e18;

int n, q, tmp;
int a, p;
vector<int> v(1);

void solve1(){

    for (int i=0 ; i<q ; i++){
        cin >> a >> p;

        for (int i=1 ; i<=p ; i++){
            a-=v[i];
            a=abs(a);
        }

        cout << a << "\n";
    }
}

void solve2(){

    vector<int> pre1(MAX_N), pre2(MAX_N);
    for (int i=1 ; i<=n ; i++){
        pre1[i]=pre1[i-1];
        pre1[i]+=v[i];

        pre2[i]=pre2[i-1];
        if (i%2==1){
            pre2[i]+=v[i];
        }else{
            pre2[i]-=v[i];
        }
    }
    // for (int i=0 ; i<=n ; i++){
    //     cerr << pre1[i] << " ";
    // }
    // cerr << "\n";
    // for (int i=0 ; i<=n ; i++){
    //     cerr << pre2[i] << " ";
    // }
    // cerr << "\n";

    for (int i=0 ; i<q ; i++){
        cin >> a >> p;

        if (a>=pre1[p]){
            cout << a-pre1[p] << "\n";
        }else{
            int ll=upper_bound(pre1.begin(), pre1.begin()+p, a)-pre1.begin()-1;
            a-=pre1[ll];

            int b=0;
            if (p%2==1){
                b=pre2[p]-pre2[ll];
            }else{
                b=-pre2[p]+pre2[ll];
            }

            if (ll%2==1){
                cout << a+b << "\n";
            }else{
                cout << b-a << "\n";
            }
        }
    }
}

signed main(void){
    int t=1;
    while (t--){

        cin >> n >> q;
        for (int i=1 ; i<=n ; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        if (n<=3000 && q<=3000){
            solve1();
        }else{
            solve2();
        }
    }
    return 0;
}

/*
3 4
7 10 2
2 1
13 2
20 2
5 3
*/

/*
5
4
3
6
*/