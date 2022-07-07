// Problem: A. Suffix Array - 1
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
using namespace std;

int main(){
	string input, str;
	vector<pair<string, int>> v;
	
	cin >> input;
	str="";
	for (int i=input.size()-1 ; i>=-1 ; i--){
		v.push_back({str, i+1});
		if (i!=-1){ // 避免掉最後一次str加上負index
			str=input[i]+str;
		}
	}
	
	sort(v.begin(), v.end());
	
	for (int i=0 ; i<=input.size() ; i++){
		cout << v[i].second << " ";
	}cout << "\n";
	return 0;
}