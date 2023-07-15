#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

signed main(void){
	fastio;
	int x1, y1, r1;
	int x2, y2, r2;
	int xs=0, ys=0;
	
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	
	if (x1<=x2 && x1+r1>=x2){
		xs = x1+r1-x2 + min((int)0, -(x1+r1-x2-r2));
	}else if (x1>x2 && x2+r2>=x1){
		xs = x2+r2-x1 + min((int)0, -(x2+r2-x1-r1));
	}
	
	if (y1<=y2 && y1+r1>=y2){
		ys = y1+r1-y2 + min((int)0, -(y1+r1-y2-r2));
	}else if (y1>y2 && y2+r2>=y1){
		ys = y2+r2-y1 + min((int)0, -(y2+r2-y1-r1));
	}
	
	cout << xs*ys << "\n";
	return 0;
}