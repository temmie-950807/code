#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        string strcp;
        char vika[a][b];
        for(int j=0;j<a;j++){
            cin >> strcp;
            for(int k=0;k<b;k++){
                vika[j][k] = strcp[k];
            }
        }
        char status[4] = {'v','i','k','a'};
        int sta = 0,found = 0,all=0;
        for(int j=0;j<b;j++){
            if(found && sta <3){
                sta++;
            }
            if(found && sta==3){
                all++;
                cout << "YES" << '\n';
                break;
            }
            found=0;
            for(int k=0;k<a;k++){
                if(vika[k][j] == status[sta]){
                    found = 1;
                    break;
                }
            }
        }
        if(!all){
            cout << "NO" << '\n';
        }
    }
}