// Problem: E. Segments with Small Set
// Memory Limit: 1024 MB
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
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
using namespace std;
using namespace __gnu_pbds;

// declare
int n, k, tmp, output=0;
vector<int> v, m(MAX_SIZE, 0);

signed main(void){
	fastio;
	
	// input
	cin >> n >> k;
	v.PB(0);
	for (int i=0 ; i<n ; i++){
		cin >> tmp;
		v.PB(tmp);
	}
	
	if (k==0) {cout << "0\n"; return 0;}
	
	// process
	int p1=1, p2=0, cnt=0;
	while (p1<=n){
		
		while (p2<n){
			if (m[v[p2+1]]==0 && cnt==k){
				// 新的元素, 但是滿了
				break;
			}else if (m[v[p2+1]]==0 && cnt<k){
				// 新的元素, 而且還有空間
				m[v[p2+1]]++;
				cnt++;
				p2++;
			}else if (m[v[p2+1]]>0){
				// 已經有這個元素
				m[v[p2+1]]++;
				p2++;
			}
		}
		
		// 新的元素, 但是滿了
		output += p2-p1+1;
		m[v[p1]]--;
		if (m[v[p1]]==0) cnt--;
		p1++;
	}
	
	// output
	cout << output << "\n";
    return 0;
}