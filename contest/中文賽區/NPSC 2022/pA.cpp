#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define vt vector
#define pb push_back


using namespace std;
const int max_n=1e6+16;
int n,m ;

int main(void){
    fio;
    
    int a;
    char word;
    cin>>a;
    string arrar[a+5];
    
    for (int k=0;k<a;k++){
        for (int i=0;i<a;i++){
            cin>>word;
            if (word=='.'){
                arrar[i]='O';
            }
            else{
                arrar[i]=word;
            }
        }
        for (int u=0;u<a;u++){
            cout<<arrar[u];
        }
        cout<<"\n";
    }
    

    return 0;
}