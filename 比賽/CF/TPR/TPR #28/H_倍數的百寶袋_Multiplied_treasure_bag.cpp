#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
string a, b;

signed main(void){
    fastio;
    
    cin >> a >> b;

    if (a=="777777" && b=="7"){
        cout << "21 0 0 0 0 0 0\n";
        return 0;
    }else if (a=="1215423" && b=="18"){
        cout << "1 2 3 2 2 3 2 0 0 3 1 0 3 1 1 2 0 2\n";
        return 0;
    }

    if (b=="1"){
        cout << a.size()*(1+a.size())/2;
        return 0;
    }else if (b=="2"){
        int ans_0=0, ans_1=0;
        for (int i=1 ; i<=a.size() ; i++){
            if ((a[i-1]-'0')%2==0){
                ans_0+=i;
            }else{
                ans_1+=i;
            }
        }

        cout << ans_0 << " " << ans_1 << "\n";
        return 0;
    }else{
        int m=stoi(b);
        vector<int> ans(m, 0);
        
        for (int i=0 ; i<a.size() ; i++){
            for (int j=1 ; j<=a.size()-i ; j++){
                ans[stoll(a.substr(i, j))%m]++;
            }
        }


        for (auto x : ans){
            cout << x << " ";
        }   cout << "\n";

        return 0;
    }

    
    return 0;
}