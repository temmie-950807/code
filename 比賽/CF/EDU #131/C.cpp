// Problem: C. Schedule Management
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

// declare
int t, n, m, tmp; // n人 m工作

signed main(void){
	fastio;
	
	cin>>t;
	while(t--){
		// input
		cin >> n >> m;
		vector<int> a(n+5);
		for(int i=1 ; i<=m ; i++){
			int x;
			cin >> x;
			a[x]++;
		}
		
		// binary search
		int l=1,r=m*2; // 左右界, 答案一定在1~2m之間
		while(l<r){
			// init
			int mid = (l+r)/2;
			int need = 0, extra = 0; // need: 還需要的時間, extra: 多的時間
			
			for(int i=1;i<=n;i++){
				if(a[i]<=mid) extra += (mid-a[i])/2; // 可以完成
				else need += a[i]-mid; // 不能完成
			}
			
			if(need<=extra)r=mid; // 多了較多時間, 答案在mid左邊(盡可能壓低)
			else l=mid+1;      // 少了較多時間, 答案在mid右邊(時間不夠, 所以變多)
		}
		
		// output
		cout << l << "\n";
	}
    return 0;
}