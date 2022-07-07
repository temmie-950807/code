#include <bits/stdc++.h>
using namespace std;

struct data{
    int value;
    int move_x;
    int move_y;
};


int main(){
    string d1, d2, output=""; // DNA1, DNA2
    data dp[51][51], d;
    int x, y, temp;

    // input
    cin >> d1 >> d2;
    x=d1.size();
    y=d2.size();

    // process - DP table
    for (int i=0 ; i<=d2.size() ; i++){
        for (int j=0 ; j<=d1.size() ; j++){
            if (i==0 || j==0) d={0, 0, 0}; // init
            else if (d1[j-1]==d2[i-1]){ // same char
                d={dp[i-1][j-1].value+1, -1, -1}; // move to left top
            }else if (dp[i-1][j].value>=dp[i][j-1].value){ // move to top
                d={dp[i-1][j].value, 0, -1};
            }else if (dp[i-1][j].value<dp[i][j-1].value){ // move to left
                d={dp[i][j-1].value, -1, 0};
            }
            dp[i][j]=d;
        }
    }

    // output
    while (x!=0 && y!=0){
        if (dp[y][x].move_x==dp[y][x].move_y) output+=d2[y-1];
        temp=dp[y][x].move_x;
        y+=dp[y][x].move_y;
        x+=temp;
    }

    if (output=="") cout << "E\n";
    else{
    reverse(output.begin(), output.end());
    cout << output << "\n";
    }
    return 0;
}
