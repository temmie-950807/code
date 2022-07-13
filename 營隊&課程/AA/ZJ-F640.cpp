#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e5+5
using namespace std;

int owo();
int f(){
	return 2*owo()-3;
}
int g(){
	return 2*owo()+owo()-7;
}
int h(){
	return 3*owo()-2*owo()+owo();
}
int owo(){
	string s;
	cin >> s;
	if (s=="f"){
		return f();
	}
	else if (s=="g"){
		return g();
	}
	else if (s=="h"){
		return h();
	}else{
		return stoi(s);
	}
}

signed main(void){
	fastio;
	
	cout << owo() << "\n";
    return 0;
}