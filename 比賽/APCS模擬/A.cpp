#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x, tmp, now, take, ans_1=0, ans_2;
vector<int> v;

signed main(void){

    cin >> n >> x; // n=day, x=left item
    take=x;
    now=x;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        v.emplace_back(tmp);
    }

    for (int i=0 ; i<n ; i++){
        if (now >= v[i]){
            ans_1+=v[i];
            now-=v[i];
        }else{
            ans_1+=now;
            now=0;
        }

        if (i==n-1) ans_2=now;

        if (now>0){
            take=max(take-1, 0LL);
            now+=take;
        }else{
            take=take+1;
            now+=take;
        }

    }

    // output
    cout << ans_1 << " " << ans_2 << "\n";

    return 0;
}