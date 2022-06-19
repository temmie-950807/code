// Problem: I. 狐狸買氣球 (Foxyy buy balloons)
// Memory Limit: 256 MB
// Time Limit: 3000 ms

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

const int max_N = 2e6+5;

signed main(void){
	fastio;
	int n, q, input;
	int l, r;
	int tmp;
	vector<int> arr(max_N), prime, lpf(max_N, 1), pre(max_N, 0); // lpf = least prime factor (第i個, 每個i的最小質因數)
	
	// 預處理
	for (int i=2 ; i<max_N ; i++){
		if (lpf[i]==1){ // 質數
			lpf[i] = i;
			prime.push_back(i);
		}
		for (int j=0 ; j<max_N ; j++){
			tmp = prime[j];
			if (i*tmp > max_N) break; // 超過範圍
			lpf[i*tmp] = tmp;         // 相同倍數lpf
			if (tmp == lpf[i]) break; // 曾經找過此prime。
		}
	}
	
	cin >> n >> q;
	for (int i=1 ; i<=n ; i++){
		cin >> input;
		arr[i]=input;

        // 計算每個輸入的美麗程度
		while (lpf[input]!=1){    // 找到最後(1, 分解完畢)
			pre[i] += lpf[input]; // 因為乘法定理, 所以直接用疊加(不用計算次數, 直接相加)
			input  /= lpf[input]; // 分解
		}
	}

	
	for (int i=1 ; i<=n ; i++) pre[i] += pre[i-1]; // 前綴和

	// 因為全部都是加法, 所以可以用前綴和
	for (int i=0 ; i<q ; i++){
		cin >> l >> r;
		cout << pre[r]-pre[l-1] << "\n";
	}
	return 0;
}