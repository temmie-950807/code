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

// declare
int n, k=58, m_num;
string s;
vector<int> L(MAX_SIZE, 1), R(MAX_SIZE, 1e9), mid(MAX_SIZE), tmp;

signed main(void){
	
	cin >> n;
    for (int i=0 ; i<n ; i++){
        mid[i] = (L[i]+R[i])/2;
    }

    while (k>0){
        tmp = mid;
        sort(tmp.begin(), tmp.begin()+n);

        if (n%2==0){
            m_num = (tmp[n/2]+tmp[n/2-1])/2;
        }else{
            m_num = tmp[n/2];
        }

        cout << "? " << m_num << "\n";
        cout.flush();

        cin >> s;
        for (int i=0 ; i<n ; i++){
            if (s[i]=='1'){
                L[i] = mid[i]+1;
            }else{
                R[i] = mid[i]-1;
            }
            mid[i] = (L[i]+R[i])/2;
        }

        // for (int i=0 ; i<n ; i++){
        //     cout << mid[i] << " ";
        // }   cout << "\n";

        k--;
    }

    

    sort(mid.begin(), mid.begin()+n);
    if (n%2==0){
        m_num = (mid[n/2]+mid[n/2-1])/2;
    }else{
        m_num = mid[n/2];
    } 

    cout << "! " << m_num << "\n";
    cout.flush();
    return 0;
}