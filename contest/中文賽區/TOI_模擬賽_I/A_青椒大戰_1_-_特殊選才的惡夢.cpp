#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF=6e18;
const int MAX_SIZE=2e5+5;

void debug(priority_queue<int, vector<int>, greater<int>> pq){
    while (pq.size()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}

// declare
int n, tmp;
int x, y;
string sp, sq;
vector<int> p, q;
bitset<MAX_SIZE> a, b, c;
bool flag=1;

int id[2][MAX_SIZE];

void solve1(){
    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        id[0][tmp]=i;
        p.push_back(tmp);
    }
    cin >> x;
    cin >> sp;

    for (int i=0 ; i<n ; i++){
        cin >> tmp;
        id[1][tmp]=i;
        q.push_back(tmp);
    }
    cin >> y;
    cin >> sq;

    // process
    int now_x=0, now_y=0;
    priority_queue<int> pq;

    while (flag){
        flag=0;

        for (int i=now_x ; i<x ; i++){
            if (sp[id[0][i]]=='1' && sq[id[1][i]]=='0'){
                if (b[id[1][i]]==1){
                    
                }

            }else if (sp[id[0][i]]=='0' && sq[id[1][i]]=='1'){
                
            }
        }

        for (int j=now_y ; j<y ; j++){

        }
    }
}

signed main(){

    int t=1;
    while (t--){
        solve1();
    }

    return 0;
}