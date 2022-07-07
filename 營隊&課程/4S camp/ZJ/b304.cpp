#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)2e5+5
using namespace std;

signed main(void){
	fastio;
    
    bool check;
    int n;
    string input;
    stack<char> s;

    cin >> n;
    cin.ignore();
    for (int i=0 ; i<n ; i++){
        // init
        check = 1;
        while (!s.empty()){
            s.pop();
        }
        
        // input
        getline(cin, input);
        
        // process
        for (int j=0 ; j<input.size() ; j++){
            if (input[j]=='(' || input[j]=='[' || input[j]=='{') s.push(input[j]);
            if (input[j]==')'){
                if (!s.empty() && s.top()=='('){
                    s.pop();
                }else{
                    check = 0;
                    break;
                }
            }
            if (input[j]==']'){
                if (!s.empty() && s.top()=='['){
                    s.pop();
                }else{
                    check = 0;
                    break;
                }
            }
            if (input[j]=='}'){
                if (!s.empty() && s.top()=='{'){
                    s.pop();
                }else{
                    check = 0;
                    break;
                }
            }
        }

        // output
        if (check && s.empty()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}