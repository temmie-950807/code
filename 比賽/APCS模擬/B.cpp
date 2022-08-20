#include <bits/stdc++.h>
#define int long long
using namespace std;

int h, w, q, tmp, k, kx, ky, ans=0;
int arr[50+5][50+5];

signed main(void){
    // init
    memset(arr, -1, sizeof(arr));

    // input
    cin >> h >> w >> q;
    for (int i=1 ; i<=h ; i++){
        for (int j=1 ; j<=w ; j++){
            cin >> tmp;
            arr[i][j]=-tmp;
        }
    }
    // arr[i][j]==0 , aka student will go to school

    for (int i=1 ; i<=q ; i++){
        // add 1 day for every student
        for (int ii=1 ; ii<=h ; ii++){
            for (int jj=1 ; jj<=w ; jj++){
                if (arr[ii][jj]<0) arr[ii][jj]++;
            }
        }

        ans=0;
        for (int i=1 ; i<=h ; i++){
            for (int j=1 ; j<=w ; j++){
                cout << arr[i][j] << " ";
            }   cout << "\n";
        }
        cout << ans << "\n";

        // input for every query(?)
        cin >> k;
        for (int j=0 ; j<k ; j++){
            cin >> kx >> ky;

            // around
            if (arr[kx][ky]<0){
                arr[kx][ky]=min(-4LL, arr[kx][ky]);
            }else{
                arr[kx][ky]=-4;
                if (arr[kx-1][ky-1]==0) arr[kx-1][ky-1]=-2;
                if (arr[kx-1][ky]==0) arr[kx-1][ky]=-2;
                if (arr[kx-1][ky+1]==0) arr[kx-1][ky+1]=-2;
                if (arr[kx][ky-1]==0) arr[kx][ky-1]=-2;
                if (arr[kx][ky+1]==0) arr[kx][ky+1]=-2;
                if (arr[kx+1][ky-1]==0) arr[kx+1][ky-1]=-2;
                if (arr[kx+1][ky]==0) arr[kx+1][ky]=-2;
                if (arr[kx+1][ky+1]==0) arr[kx+1][ky+1]=-2;
            }
        }

    }

    for (int ii=1 ; ii<=h ; ii++){
        for (int jj=1 ; jj<=w ; jj++){
            arr[ii][jj]++;
        }
    }

    ans=0;
    for (int i=1 ; i<=h ; i++){
        for (int j=1 ; j<=w ; j++){
            if (arr[i][j]>=0) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}