#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

// declare
const int MAX_N = 5e5+5;
const int INF = 2e18;

int n, m, k;
string s;
vector<int> pre(MAX_N);

int f(int x){
    int ret=0;
    ret+=(x/n)*pre[n]; // 計算有多少組完整的 s
    ret+=pre[x%n];     // 將剩下的前綴補上
    return ret;
}

void solve1(){
    
    // input
    cin >> n >> m >> k;
    cin >> s;

    // 建立前綴和陣列
    for (int i=0 ; i<n ; i++){
        pre[i+1]=pre[i]+(s[i]=='x');
    }

    // process
    int ma=-INF;
    for (int i=1 ; i<=n ; i++){ // 枚舉所有起點
        int ll=i, rr=n*m+1, ans; // 我是用 [ll, rr) 的寫法

        while (ll<rr){
            int mid=(ll+rr)/2;
            if (f(mid)-pre[i-1]<=k){ // 二分搜檢查目前的 [i, mid] 的 x 數量有沒有超過 k
                ll=mid+1;
                ans=mid;
            }else{
                rr=mid;
            }
        }

        ma=max(ma, ans-i+1);
    }

    // output
    cout << ma << "\n";

    return;
}

signed main(void){
    fastio;
    
    int t=1;
    while (t--){
        solve1();
    }
    return 0;
}