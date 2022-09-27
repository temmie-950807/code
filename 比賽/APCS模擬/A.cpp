#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x, tmp, now, take, ans_1=0, ans_2;
vector<int> v;

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

signed main(void){

    n=nextint();
    x=nextint();
    take=x;
    now=x;
    for (int i=0 ; i<n ; i++){
        tmp=nextint();
        v.emplace_back(tmp);
    }

    for (int i=0 ; i<n ; i++){
        if (now >= v[i]){
            ans_1+=v[i];
            now-=v[i];
        }else{
            ans_1+=now;
            now=0;
        }

        if (i==n-1) ans_2=now;

        if (now>0){
            take=max(take-1, 0LL);
            now+=take;
        }else{
            take=take+1;
            now+=take;
        }

    }

    // output
    cout << ans_1 << " " << ans_2 << "\n";

    return 0;
}