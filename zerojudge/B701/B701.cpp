#include <iostream>
#include <queue>
using namespace std;

struct position{
    int x;
    int y;
};


int main(){
    int x, y;
    int array[512][512];
    int move_x[4]={0, 1, 0, -1}, move_y[4]={-1, 0, 1, 0};
    queue<position> BFS;

    // input
    cin >> x >> y;
    for (int i=0 ; i<y ; i++){
        for (int j=0 ; j<x ; j++){
            cin >> array[i][j];
        }
    }

    // process
    for (int i=0 ; i<y ; i++){
        for (int j=0 ; j<x ; j++){
            // check if a land
            if (array[i][j] == 1){
                // do BFS
                int N=999, S=-1, W=999, E=-1, area=0;
                position p={j, i};
                BFS.push(p);
                array[i][j]=0;

                while (BFS.size() != 0){
                    // do move
                    area++;

                    // check if output needed value
                    if (BFS.front().y < N) N=BFS.front().y;
                    if (BFS.front().y > S) S=BFS.front().y;
                    if (BFS.front().x < W) W=BFS.front().x;
                    if (BFS.front().x > E) E=BFS.front().x;

                    // push BFS
                    for (int k=0 ; k<4 ; k++){
                        if (array[BFS.front().y + move_y[k]][BFS.front().x + move_x[k]] == 1){
                            p={BFS.front().x + move_x[k], BFS.front().y + move_y[k]};
                            array[BFS.front().y + move_y[k]][BFS.front().x + move_x[k]]=0;
                            BFS.push(p);
                        }
                    }

                    // pop front
                    BFS.pop();
                }

                // output
                cout << W << " " << N << " " << E << " " << S << " " << area << "\n";
            }
        }
    }
    return 0;
}