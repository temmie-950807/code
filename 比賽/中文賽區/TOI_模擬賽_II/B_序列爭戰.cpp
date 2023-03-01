#include <bits/stdc++.h>
#define int long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// declare
const int MAX_SIZE=1e5+5;
const int INF=6e18;

int n, m, l, e;
int x, t;
vector<double> ans;

// function
double check(double mid){
    double aa=(mid*l+x)/t;
    double bb=((m*l)-(mid*l+x))/(e-t);
    return max(aa, bb);
}

void solve1(){
    // input
    for (int i=0 ; i<n ; i++){
        double ans_1=INF;
        cin >> x >> t;


        for (int j=0 ; j<m ; j++){
            ans_1=min(ans_1, check(j));
        }

        // output
        cout << fixed << setprecision(15) << ans_1 << "\n";
        return;
    }
}

void solve2(){
    // input

    // queries
    int ll, rr;
    double ml, mr;
    for (int i=0 ; i<n ; i++){

        ll=0, rr=m;
        cin >> x >> t;

        // 三分搜
        for (int i=0 ; i<200 ; i++){
            ml=ll+(rr-ll)/3;
            mr=rr-(rr-ll)/3;

            if (check(ml)<check(mr)){
                rr=mr;

            }else{
                ll=ml+1;

            }
        }

        cout << fixed << setprecision(20) << check(ll) << "\n";
        return;
    }

    // output
    // for (auto x : ans){
    //     cout << fixed << setprecision(15) << check(x) << "\n";
    // }   cout << "\n";
}

signed main(){
    cin >> n >> m >> l >> e;
    
    if (m<=500){
        solve1();
    }else{
        solve2();
    }

    return 0;
}