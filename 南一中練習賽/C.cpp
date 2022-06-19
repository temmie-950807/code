
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
const int max_N = 2*10e5+5;
 
signed main(void){
	fastio;
	int n, L, e, tmp, ma=0, a, b;
	cin >> n >> L >> e;
	vector<int> p(n);
	
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		p[i]=tmp;
	}
	
	if (n>1){
		sort(p.begin(), p.end());
		for (int i=0 ; i<n-1 ; i++){ // 尋找最大的區間
			if (p[i+1]-p[i]>ma){
				a = p[i+1];
				b = p[i];
				ma = a-b;
			}
		}
		if (p[0]>ma){
				a = p[0];
				b = 1;
				ma = a-b;
		}
		if (L-p[n-1]>ma){
				a = L;
				b = p[n-1];
				ma = a-b;
		}
		
		
		if (a==p[0] && b==1){
			cout << e-(p[0]-1) << "\n";
		}else if (a==L && b==p[n-1]){
			cout << e-(L-p[n-1]) << "\n";
		}else if((ma&1) == 0){
			int x = max((int)0, e-(a-(a+b)/2));
			cout << x << "\n";
		}else{
			int x = max((int)0, e-(a-(a+b)/2));
			int y = max((int)0, e-(a-(a+b)/2)+1);
			cout << max(x, y) << "\n";
		}
	}else{
		int mi=2*10e9;
		for (int i=1 ; i<=L ; i++){
			mi = min(mi, max((int)0, e-abs(i-p[0])));
		}
		cout << mi << "\n";
	}
	
	return 0;
}