#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int n, k, tmp, ans=0;
vector<int> a, b, c;

signed main(void){
    fastio;
    
    cin >> n >> k;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        if (tmp>0){
            a.push_back(tmp);
        }else if (tmp==0){
            c.push_back(tmp);
        }else if (tmp<0){
            b.push_back(tmp);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    // process
    int p1=0, p2=a.size()-1, p3=0, p4=b.size()-1, p5=0; // p1 p2: 正數, p3 p4: 負數, p5: 0;
    for (int i=0 ; i<k ; i++){
        if ((p2-p1+1)>=2 && (p4-p3+1)>=2){ // 有兩種選擇
            if (a[p2]*a[p2-1] >= b[p4]*b[p4-1]){ // 優先選正數
                // cout << "A: " << a[p2]*a[p2-1] << "\n";
                ans += a[p2]*a[p2-1];
                p2 -= 2;
            }else if (a[p2]*a[p2-1] < b[p4]*b[p4-1]){ // 優先選負數
                // cout << "B: " << b[p4]*b[p4-1] << "\n";
                ans += b[p4]*b[p4-1];
                p4 -= 2;
            }
        }else if ((p2-p1+1)>=2 && (p4-p3+1)<2){ // 只能選正數
            // cout << "C: " << a[p2]*a[p2-1] << "\n";
            ans += a[p2]*a[p2-1];
            p2 -= 2;
        }else if ((p2-p1+1)<2 && (p4-p3+1)>=2){ // 只能選負數
            // cout << "D: " << b[p4]*b[p4-1] << "\n";
            ans += b[p4]*b[p4-1];
            p4 -= 2;
        }else if ((p2-p1+1)<2 && (p4-p3+1)<2 && p5<c.size()){ // 兩邊都不能選 但還有0
            // cout << "E\n";
            p4--;
            p5++;
        }else if ((p2-p1+1)<2 && (p4-p3+1)<2 && p5>=c.size()){ // 兩邊都不能選 且沒有0可以用
            // cout << "F: " << a[p1]*b[p3] << "\n";
            ans += a[p1]*b[p3];
            p1++;
            p3++;
        }
    }

    // output
    cout << ans << "\n";
    return 0;
}