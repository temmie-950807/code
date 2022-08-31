#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MAX_SIZE = 1e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

// declare
int t, h, w;
string s, ans;
int mx[8]={1, 1, 1, 0, 0, -1, -1, -1};
int my[8]={1, 0, -1, 1, -1, 1, 0, -1};
char arr[55][55];

signed main(void){
    fastio;
    
    cin >> t;
    while (t--){
        // init
        ans="YES\n";

        // input
        cin >> h >> w;
        for (int i=1 ; i<=h ; i++){
            cin >> s;
            for (int j=1 ; j<=w ; j++){
                arr[i][j]=s[j];
            }
        }
        
        for (int i=1 ; i<=h && ans=="YES\n" ; i++){
            for (int j=1 ; j<=w && ans=="YES\n" ; j++){

                int check=0;
                if (arr[i][j]=='*'){
                    if (arr[i-1][j]!='*' && arr[i][j-1]!='*' && arr[i+1][j]!='*' && arr[i][j+1]!='*') check=-100; // 四周都沒有
                    if (arr[i-1][j]=='*' && arr[i][j-1]!='*' && arr[i+1][j]=='*' && arr[i][j+1]!='*') check=-100; // 一直線
                    if (arr[i-1][j]!='*' && arr[i][j-1]=='*' && arr[i+1][j]!='*' && arr[i][j+1]=='*') check=-100; // 一直線
                    
                    if (arr[i-1][j]=='*' && arr[i][j-1]=='*' && arr[i+1][j]!='*' && arr[i][j+1]!='*') check++; // L形
                    if (arr[i-1][j]=='*' && arr[i][j-1]!='*' && arr[i+1][j]!='*' && arr[i][j+1]=='*') check++; // L形
                    if (arr[i-1][j]!='*' && arr[i][j-1]!='*' && arr[i+1][j]=='*' && arr[i][j+1]=='*') check++; // L形
                    if (arr[i-1][j]!='*' && arr[i][j-1]=='*' && arr[i+1][j]=='*' && arr[i][j+1]!='*') check++; // L形

                    cout << i << " " << j << "\n";
                    cout << "checK: " << check << "\n";

                    if (check<0){
                        ans="NO\n";
                    }else if (check==1){
                        int x1=i, y1=j;
                        int x2=0, y2=0;
                        int x3=0, y3=0;

                        

                        if (arr[i-1][j]=='*'){
                            if (x2==0 && y2==0){
                                x2=i-1;
                                y2=j;
                            }else{
                                x3=i-1;
                                y3=j;
                            }
                        }
                        if (arr[i+1][j]=='*'){
                            if (x2==0 && y2==0){
                                x2=i+1;
                                y2=j;
                            }else{
                                x3=i+1;
                                y3=j;
                            }
                        }
                        if (arr[i][j-1]=='*'){
                            if (x2==0 && y2==0){
                                x2=i;
                                y2=j-1;
                            }else{
                                x3=i;
                                y3=j-1;
                            }
                        }
                        if (arr[i][j+1]=='*'){
                            if (x2==0 && y2==0){
                                x2=i;
                                y2=j+1;
                            }else{
                                x3=i;
                                y3=j+1;
                            }
                        }

                        // cout << x1 << " " << y1 << "\n";
                        // cout << x2 << " " << y2 << "\n";
                        // cout << x3 << " " << y3 << "\n";

                        arr[x1][y1]='-';
                        arr[x2][y2]='-';
                        arr[x3][y3]='-';

                        for (int i=0 ; i<8 ; i++){
                            if (arr[x1+mx[i]][y1+my[i]]=='-'){
                                continue;
                            }else if (arr[x1+mx[i]][y1+my[i]]=='*'){
                                ans="NO\n";
                            }else{
                                arr[x1+mx[i]][y1+my[i]]='#';
                            }
                        }
                        for (int i=0 ; i<8 ; i++){
                            if (arr[x2+mx[i]][y2+my[i]]=='-'){
                                continue;
                            }else if (arr[x2+mx[i]][y2+my[i]]=='*'){
                                ans="NO\n";
                            }else{
                                arr[x2+mx[i]][y2+my[i]]='#';
                            }
                        }
                        for (int i=0 ; i<8 ; i++){
                            if (arr[x3+mx[i]][y3+my[i]]=='-'){
                                continue;
                            }else if (arr[x3+mx[i]][y3+my[i]]=='*'){
                                ans="NO\n";
                            }else{
                                arr[x3+mx[i]][y3+my[i]]='#';
                            }
                        }

                        for (int i=0 ; i<55 ; i++){
                            for (int j=0 ; j<55 ; j++){
                                if (arr[i][j]=='-'){
                                    arr[i][j]='#';
                                }
                            }
                        }

                    }else if (check>1){
                        ans="NO\n";
                    }

                    for (int i=0 ; i<=h ; i++){
                        for (int j=0 ; j<=w ; j++){
                            cout << arr[i][j];
                        }   cout << "\n";
                    }
                }
            }
        }

        // output
        cout << ans;
        
    }
    return 0;
}