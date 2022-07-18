// Problem: Subarray Distinct Values
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define PB push_back
const int MAX_SIZE = 2e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, k, tmp, output=0;
vector<int> v, m(MAX_SIZE, 0);

signed main(void){
	// fastio;
	
	// input
	cin >> n >> k;
	v.PB(0);
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		v.PB(tmp);
	}
	vector<int> rank = v;
	sort(rank.begin(), rank.end());
	rank.resize(unique(rank.begin(), rank.end())-rank.begin());
	
	// process
	int p1=1, p2=0, cnt=0, pos=0;
	while (p1<=n){
		
		while (p2<n){
			pos = lower_bound(rank.begin(), rank.end(), v[p2+1])-rank.begin();
			if (m[pos]==0 && cnt==k){
				// 新的元素, 但是滿了
				break;
			}else if (m[pos]==0 && cnt<k){
				// 新的元素, 而且還有空間
				m[pos]++;
				cnt++;
				p2++;
			}else if (m[pos]>0){
				// 已經有這個元素
				m[pos]++;
				p2++;
			}
		}
		
		// 新的元素, 但是滿了
		pos = lower_bound(rank.begin(), rank.end(), v[p1])-rank.begin();
		output += p2-p1+1;
		m[pos]--;
		if (m[pos]==0) cnt--;
		p1++;
	}
	
	// output
	cout << output << "\n";
    return 0;
}