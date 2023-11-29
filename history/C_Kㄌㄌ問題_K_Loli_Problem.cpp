#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N=505;
int k, n;
vector<bitset<MAX_N>> vis(MAX_N);

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout.flush();

    int tmp;
    cin >> tmp;
    return tmp;
}

void answer(int a, int b){
    cout << "! " << a << " " << b << "\n";
    cout.flush();
    exit(0);
    return;
}

int get_total(){
    int ret=0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            ret+=(vis[i][j]==0);
        }
    }
    return ret;
}

void push(int x, int y, int ty){
    if (ty==0){
        for (int i=0 ; i<=x ; i++){
            for (int j=0 ; j<=y ; j++){
                vis[i][j]=1;
            }
        }

    }else if (ty==1){
        for (int i=x ; i<n ; i++){
            for (int j=y ; j<n ; j++){
                vis[i][j]=1;
            }
        }

    }
}

void solve1(){

    // queries
    for (int i=0 ; i<2*n ; i++){
        int total=get_total();
        if (total==0) break;
        int add=rand()%total+1;
        int now=0;

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                now+=(vis[i][j]==0);
                if (now==add){
                    int res=query(i+1, j+1);
                    if (res==k) answer(i+1, j+1);
                    if (res<k) push(i, j, 0);
                    if (res>k) push(i, j, 1);
                    goto flag;
                }
            }
        }

        flag:;
    }

    answer(-1, -1);
    return;
}

void solve2(){

    int guess=0;
    for (int i=n-1 ; i>=0 ; i--){
        int total=get_total();
        if (total==0) break;

        int j=n-1-i;
        if (rand()%3 && vis[i][j]==0){
            guess++;
            int res=query(i+1, j+1);
            if (res==k) answer(i+1, j+1);
            if (res<k) push(i, j, 0);
            if (res>k) push(i, j, 1);
        }
    }

    // queries
    for (int i=guess ; i<2*n ; i++){
        int total=get_total();
        if (total==0) break;
        int add=rand()%total+1;
        int now=0;

        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                now+=(vis[i][j]==0);
                if (now==add){
                    int res=query(i+1, j+1);
                    if (res==k) answer(i+1, j+1);
                    if (res<k) push(i, j, 0);
                    if (res>k) push(i, j, 1);
                    goto flag;
                }
            }
        }

        flag:;
    }

    answer(-1, -1);
    return;
}

signed main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t=1;
    while (t--){

        // init
        srand(time(NULL));

        // input
        cin >> k >> n;

        // process
        solve2();
        // if (n<=50){
        //     solve1();
        // }else{
        //     solve2();
        // }
    }
    return 0;
}