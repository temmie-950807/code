// Problem: H2. 區間求和問題 (Range Sum Queries)【Two-dimensional Version】
// Memory Limit: 512 MB
// Time Limit: 4000 ms
 
#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
 
 int input[2500+5][2500+5];
 
signed main(void){
	fastio;
	int n, m;
	
	
	cin >> n >> m;
	for (int i=0 ; i<=n ; i++){
		for (int j=0 ; j<=m ; j++){
			if (i==0 || j==0){
				input[i][j] = 0;
			}else{
				cin >> input[i][j];
				input[i][j]=input[i][j]+input[i][j-1]+input[i-1][j]-input[i-1][j-1];
			} 
		}
	}
	
	int q;
	int x1, y1, x2, y2;
	
	cin >> q;
	for (int i=0 ; i<q ; i++){
		cin >> y1 >> x1 >> y2 >> x2;
		cout << input[y2+1][x2+1] - input[y2+1][x1] - input[y1][x2+1] + input[y1][x1] << "\n";
	}
	
	return 0;
}