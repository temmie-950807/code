#include <iostream>
#include <queue>
using namespace std;

struct position{
    int x;
    int y;
    int color;
};

int main(){
    int N, output=0;
    int input_array[10][10] = {0};
    int x, y, color;
    int move_x[4] = {0, 1, 0, -1}, move_y[4] = {1, 0, -1, 0};
    queue<position> BFS_queue;

    // input
    cin >> N;
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            cin >> input_array[i][j];
        }
    }

    // process
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            if (input_array[i][j]){

                // 定義第一項, 並推入queue中
                output++;
                position first;
                first.x = j, first.y = i, first.color = input_array[i][j];
                BFS_queue.push(first);

                // Do BFS
                while (BFS_queue.size()){
                    x = BFS_queue.front().x;
                    y = BFS_queue.front().y;
                    color = BFS_queue.front().color;

                    input_array[y][x] = 0;
                    BFS_queue.pop();

                    for (int k=0 ; k<4 ; k++){
                        if (y+move_y[k] >= 0 && y+move_y[k] < N && x+move_x[k] >= 0 && x+move_x[k] < N && input_array[y+move_y[k]][x+move_x[k]] == color){
                            position add;
                            add.x = x+move_x[k], add.y = y+move_y[k], add.color = color;
                            BFS_queue.push(add);
                        }
                    }
                }
                
            }
        }
    }
    cout << output;
    // system("pause");
    return 0;
}