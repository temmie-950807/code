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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int t, n, m, ans=0;

inline char readchar(){
	static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
	if (now == end)
	{
		if (end < buffer + BUFSIZ)
			return EOF;
		end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
		now = buffer;
	}
	return *now++;
}
inline int nextint(){
	int x = 0, c = readchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = true, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}

// function
void f(int x, int cnt){
	if (cnt>m || (m-cnt)/6>(n-x)){
		return;
	}else if (x==n){
		if (cnt==m){
			ans++;
		}
		return;
	}else{
		for (int i=1 ; i<=6 ; i++){
			f(x+1, cnt+i);
		}
	}
}

signed main(void){
	fastio;
	
	cin >> t;
	while (t--){
		// init
		ans=0;

		// input
		cin >> n >> m;
		f(0, 0);
		cout << ans << "\n";
		
	}
	return 0;
}