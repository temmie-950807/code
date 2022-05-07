#include <iostream>
#include <queue>
using namespace std;

struct position{
    int x;
    int y;
    int counter;
};


int main(){
    int S; // S=1: 可以往上流, S=2: 不能往上流
    int N, M; // N列 M行
    int x, y, counter; // 目前位置, 同上, 時間
    int move_x[4] = {0, 1, 0, -1}, move_y[4] = {-1, 0, 1, 0}; // 移動方向
    int Case = 1;

    while (cin >> S){
        // init
        int input_array[100][100] = {0}, output_array[100][100] = {0};;
        queue<position> BFS_queue;

        // input
        cin >> N >> M;
        for (int i=0 ; i<N ; i++){
            for (int j=0 ; j<M ; j++){
                cin >> input_array[i][j];
            }
        }

        // find start point
        for (int j=0 ; j<M ; j++){
            if (input_array[0][j]){
                position start;
                start.x = j, start.y=0, start.counter=1;
                BFS_queue.push(start);
            }
        }

        // do BFS
        while (BFS_queue.size()){
            x = BFS_queue.front().x;
            y = BFS_queue.front().y;
            counter = BFS_queue.front().counter;

            output_array[y][x] = counter; // 製作輸出
            input_array[y][x] = 0; // 確認走訪(防止逆流)

            for (int i=S-1 ; i<4 ; i++){
                if (input_array[y+move_y[i]][x+move_x[i]]){
                    position add;
                    add.x = x+move_x[i], add.y = y+move_y[i], add.counter = counter+1;
                    BFS_queue.push(add); // 加入新方向
                }
            }
            BFS_queue.pop();
        }
        
        // output
        cout << "Case " << Case++ << ":" << "\n";
        for (int i=0 ; i<N ; i++){
            for (int j=0 ; j<M ; j++){
                cout << output_array[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}