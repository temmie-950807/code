#include <bits/stdc++.h>
using namespace std;
#define int long long

// 宣告
int n, tmp;
int arr[400][400], vis[4][400][400];
int op1, op2; // op1: 最小的相差值，op2: 最小的長度

const int mx[4]={1, 0, -1, 0};
const int my[4]={0, 1, 0, -1};

struct position{
    int x;
    int y;
    int len;
};

// check函式
bool check(int mid){
    //初始化
    memset(vis, 0, sizeof(vis));
    queue<position> que;
    que.push({1, 1, 0});

    // 記得紀錄vis
    vis[0][1][1]=1;
    vis[1][1][1]=1;
    vis[2][1][1]=1;
    vis[3][1][1]=1;

    // BFS 流程
    while (que.size()){
        position now=que.front();
        que.pop();

        // 確認是否抵達終點（因為BFS的特性，最先到終點的一定是答案）
        if (now.x==n && now.y==n){
            op1=mid;
            op2=now.len;
            return 1;
        }

        // 繼續尋找周圍的點
        for (int j=0 ; j<4 ; j++){
            int next=arr[now.x+mx[j]][now.y+my[j]];

            if (next!=-1 && vis[j][now.x+mx[j]][now.y+my[j]]==0 && abs(next-arr[now.x][now.y])<=mid){
                que.push({now.x+mx[j], now.y+my[j], now.len+1});
                vis[j][now.x+mx[j]][now.y+my[j]]=1;
            }
        }
    }
    return 0;
}

signed main(void){
    // 輸入
    cin >> n;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            // 使用based 1，待會邊界比較好寫
            cin >> arr[i][j];
        }
    }

    // 初始化邊界，用-1代表
    for (int i=0 ; i<=n+1 ; i++){
        arr[0][i]=-1;
        arr[n+1][i]=-1;
        arr[i][0]=-1;
        arr[i][n+1]=-1;
    }

    // 二分搜 (左閉右開寫法)
    int l=0, r=1e6+1, mid;
    while (l<r){
        mid=l+(r-l)/2;

        if (check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }

    // 輸出
    cout << op1 << "\n" << op2 << "\n";
    return 0;
}