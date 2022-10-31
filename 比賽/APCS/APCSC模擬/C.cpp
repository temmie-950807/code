#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a, b, c, t, ans=0;
vector<int> k, node(200000+5, -1), G[200000+5];
queue<pair<int, int>> q;

// fast IO
inline char readchar(){
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}
inline int nextint(){
    int x = 0, c = readchar(), neg = false;
    while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
    if(c == '-') neg = true, c = readchar();
    while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
    if(neg) x = -x;
    return x; // returns 0 if EOF
}

void BFS(int now, int t){
    // init
    while (q.size())q.pop();
    
    // main
    q.push({now, 0});
    while (q.size()){
        now=q.front().first;
        t=q.front().second; // time
        q.pop();

        if (node[now]==-1){
            node[now]=t;
        }else{
            node[now]=min(node[now], t);
        }

        for (int i=0 ; i<G[now].size() ; i++){
            if (node[G[now][i]]==-1){
                q.emplace(G[now][i], t+1);
            }else{
                if (node[G[now][i]] > t+1){
                    q.emplace(G[now][i], t+1);
                }
            }
        }
    }
    
}

signed main(void){

    n=nextint();
    m=nextint();
    for (int i=0 ; i<n-1 ; i++){
        a=nextint();
        b=nextint();
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for (int i=0 ; i<m ; i++){
        c=nextint();
        k.emplace_back(c);
        node[c]=0;
    }

    // BFS
    for (int i=0 ; i<m ; i++){
        BFS(k[i], 0);
    }

    // output
    // for (int i=1 ; i<=n ; i++){
    //     cout << node[i] << " ";
    // }   cout << "\n";
    for (int i=1 ; i<=n ; i++){
        ans+=node[i];
    }
    cout << ans << "\n";

    return 0;
}