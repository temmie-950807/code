#include <bits/stdc++.h>
using namespace std;
#define int long long

// 宣告
int r, c, n, tmp;
int op1=0, op2=0; // op1: 維護有多少格子被放置, op2: 維護有多少貨物放不進去
char type;
vector<pair<char, int>> v; // 維護輸入
int arr[100][100]; // 貨櫃版面, 0: 空格，1: 正在放入的貨物，2: 邊界或是已經放入的貨物

signed main(void){
    // 初始化版面
    for (int i=0 ; i<100 ; i++){
        arr[i][0]=2;
    }
    
    // 輸入
    cin >> r >> c >> n;
    for (int i=0 ; i<n ; i++){
        cin >> type >> tmp;
        v.push_back({type, tmp});
    }

    // 放入貨物
    for (int i=0 ; i<n ; i++){
        pair<int, int> block[5]; // 貨物的每個方格座標
        int block_cnt; // 貨物的大小
        
        // 生成貨物 & 設定初始座標(x=60為起點)
        if (v[i].first=='A'){
            block_cnt=4;
            block[0]={v[i].second, 60};
            block[1]={v[i].second+1, 60};
            block[2]={v[i].second+2, 60};
            block[3]={v[i].second+3, 60};
        }
        if (v[i].first=='B'){
            block_cnt=3;
            block[0]={v[i].second, 60};
            block[1]={v[i].second, 61};
            block[2]={v[i].second, 62};
        }
        if (v[i].first=='C'){
            block_cnt=4;
            block[0]={v[i].second, 60};
            block[1]={v[i].second+1, 60};
            block[2]={v[i].second, 61};
            block[3]={v[i].second+1, 61};
        }
        if (v[i].first=='D'){
            block_cnt=4;
            block[0]={v[i].second+1, 60};
            block[1]={v[i].second+1, 61};
            block[2]={v[i].second, 62};
            block[3]={v[i].second+1, 62};
        }
        if (v[i].first=='E'){
            block_cnt=5;
            block[0]={v[i].second+1, 60};
            block[1]={v[i].second+2, 60};
            block[2]={v[i].second, 61};
            block[3]={v[i].second+1, 61};
            block[4]={v[i].second+2, 61};
        }

        // 在初始地點放置貨物
        for (int j=0 ; j<block_cnt ; j++){
            arr[block[j].first][block[j].second]=1;
        }

        // 移動貨物直到不能移動
        bool check=1;
        while (1){
            for (int j=0 ; j<block_cnt ; j++){
                if (arr[block[j].first][block[j].second-1]==2){
                    check=0;
                    break;
                }
            }

            if (check){
                // 每個方塊都可以被移動，更新版面
                for (int j=0 ; j<block_cnt ; j++){
                    arr[block[j].first][block[j].second]=0;
                    arr[block[j].first][block[j].second-1]=1;
                    block[j].second--;
                }
                continue;
            }else{
                // 不能被移動了，確認是否有超出範圍
                check=1;
                for (int j=0 ; j<block_cnt ; j++){
                    if (block[j].second>c){
                        check=0;
                    }
                }

                if (check){
                    // 可以被放置，更新op1以及目前版面
                    op1+=block_cnt;
                    for (int j=0 ; j<block_cnt ; j++){
                        arr[block[j].first][block[j].second]=2;
                    }
                }else{
                    // 不能被放置，更新op2以及清掉貨物
                    op2++;
                    for (int j=0 ; j<block_cnt ; j++){
                        arr[block[j].first][block[j].second]=0;
                    }
                }

                break;
            }
        }
    }

    // 輸出
    cout << r*c-op1 << " " << op2 << "\n"; // 因為op1維護有多少格子被放置，記得要用貨物箱大小扣除
    return 0;
}