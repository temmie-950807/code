#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<pair<int, int>> v;
const int mx[4]={1, 0, -1, 0};
const int my[4]={0, 1, 0, -1};

mt19937 seed(time(NULL));
int rnd(int l, int r){
    return uniform_int_distribution<int>(l, r)(seed);
}
double drnd(double l, double r){
    return uniform_real_distribution<double>(l, r)(seed);
}

bool in(int x, int y){
    return 0<=x && x<=10000 && 0<=y && y<=10000;
}

double calc(int x, int y){
    double ret=0;

    for (int i=0 ; i<n ; i++){
        ret+=sqrt((x-v[i].first)*(x-v[i].first) + (y-v[i].second)*(y-v[i].second));
    }

    return ret;
}

double P(int now, int nxt, int temp){
    if (now>nxt){
        return 1.0;
    }else{
        return exp(1.0*(now-nxt)/temp);
    }
}

int main(){

    // input
    cin >> n;
    for (int i=0 ; i<n ; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    // process
    double mi=5e18;
    for (int i=0 ; i<20 ; i++){
        int now_x=0, now_y=0;
        double now=calc(now_x, now_y);

        for (double temp=1 ; temp>1e-6 ; temp*=0.99){
            int dir;
            int step;
            do{
                dir=rnd(0, 3);
                step=rnd(1, 100);
            } while (!in(now_x+mx[dir]*step, now_y+my[dir]*step));
            
            double nxt=calc(now_x+mx[dir]*step, now_y+my[dir]*step);
            mi=min(mi, nxt);

            if (P(now, nxt, temp)>=drnd(0, 1)){
                now_x=now_x+mx[dir]*step;
                now_y=now_y+my[dir]*step;
                now=nxt;
            }
        }
    }

    // output
    cout << round(mi) << "\n";
}