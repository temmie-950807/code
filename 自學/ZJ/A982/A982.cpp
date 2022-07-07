#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct position{
    int x;
    int y;
    int d; // 距離
};

int main(){
    int n, min=9999999;
    int move_x[4] = {1, 0, -1, 0}, move_y[4] = {0, 1, 0, -1};
    string input;
    queue<position> bfs_queue;
    cin >> n;

    vector<bool> maze[n];

    for (int i=0 ; i<n ; i++){
        cin >> input;
        for (int j=0 ; j<n ; j++){
            if (input[j] == '#') maze[i].push_back(1);
            else maze[i].push_back(0);
        }
    }

    position p;
    p.x = 1, p.y = 1, p.d = 1;
    bfs_queue.push(p);

    while (bfs_queue.size()!=0){
        // init
        int x = bfs_queue.front().x;
        int y = bfs_queue.front().y;
        int d = bfs_queue.front().d;

        // check traverse
        maze[y][x] = 1;
        bfs_queue.pop();

        // check find end
        if (x == n-2 && y == n-2 && d < min) min = d;

        for (int i=0 ; i<4 ; i++){
            if (maze[y+move_y[i]][x+move_x[i]] == 0){
                p.x = x+move_x[i], p.y = y+move_y[i], p.d = d+1;
                bfs_queue.push(p);
            }
        }
    }

    if (min != 9999999){
        cout << min << "\n";
    }else cout << "No solution!\n";
    
    // system("pause");
    return 0;
}