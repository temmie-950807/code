#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

// 左右盡可能大, 左右盡可能平均

signed main(void){
	fastio;
	int n, tmp;
	int total;
	cin >> n;
	vector<int> v;
	
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	// flip number
	sort(v.begin(), v.end());
	v[n-1]=-v[n-1];

	// count real need flip
	int cnt_1=0;
	int cnt_2=0;
	for (int i=0 ; i<n ; i++){
		if (v[i]>0) cnt_1++;
		if (v[i]<0) cnt_2++;
	}
	
	// flip number
	int pointer=0;
	if ((cnt_1+cnt_2)%2==0){
		while (1){
			if (cnt_1==cnt_2 || pointer>n-1) break;
			if (v[pointer]==0){
				pointer++;
				continue;
			}
			v[pointer]=-v[pointer];
			cnt_1--;
			cnt_2++;
			pointer++;
		}
	}else{
		while (1){
			if (cnt_1==cnt_2-1 || pointer>n-1) break;
			if (v[pointer]==0){
				pointer++;
				continue;
			}
			v[pointer]=-v[pointer];
			cnt_1--;
			cnt_2++;
			pointer++;
		}
	}


	for (int i=0 ; i<n ; i++){
		cout << v[i] << " ";
	}cout << "\n";
	sort(v.begin(), v.end());
	
	// get total
	total=0;
	for (int i=0 ; i<n ; i++){
		for (int j=i+1 ; j<n ; j++){
			total += abs(v[i]-v[j]);
		}
	}
	
	cout << total << "\n";
	return 0;
}