/*https://pastecode.io/s/sjdnh7a9*/
#include <bits/stdc++.h>
#define whitebear ios_base::sync_with_stdio(0), cin.tie(0) , cout.tie(0)
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
 
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               媽祖保佑         永無BUG
//
//
//

/*
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
*/

/*
觀自在菩薩，行深般若波羅蜜多時，照見五蘊皆空，度一切苦厄。
舍利子！色不異空，空不異色；色即是空，空即是色，受想行識亦復如是。
舍利子！是諸法空相，不生不滅，不垢不淨，不增不減。
是故，空中無色，無受想行識；無眼耳鼻舌身意；無色聲香味觸法；
無眼界，乃至無意識界；無無明，亦無無明盡，乃至無老死，亦無老死盡；
無苦集滅道；無智亦無得。以無所得故，菩提薩埵。
依般若波羅蜜多故，心無罣礙；無罣礙故，無有恐怖，遠離顛倒夢想，究竟涅槃。
三世諸佛，依般若波羅蜜多故，得阿耨多羅三藐三菩提。
故知：般若波羅蜜多是大神咒，是大明咒，是無上咒，是無等等咒，能除一切苦，真實不虛。
故說般若波羅蜜多咒，即說咒曰：揭諦揭諦，波羅揭諦，波羅僧揭諦，菩提薩婆訶。

有般若波羅蜜多心經護體，你還怕有 bug 嗎?
*/

//usage cin >> n -> n = nextint()
inline char readchar() {
   const int S = 1<<20; // buffer size
   static char buf[S], *p = buf, *q = buf;
   if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
   return *p++;
}
 
inline int nextint() {
   int x = 0, c = getchar(), neg = false;
   while(('0' > c || c > '9') && c!='-' && c!=EOF) c = getchar();
   if(c == '-') neg = true, c = getchar();
   while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = getchar();
   if(neg) x = -x;
   return x; // returns 0 if EOF
}

/*
函數說明owo:

string -> 你的名字
int -> 權重
bool -> 你有沒有猜最後上的學校

一開始的權重根據你的留言而定，如果你留的是頂大，權重為 3，中字是 2，地名是 1
然後接下來權重會經過一輪線性的變換
如果我最後上的學校是頂大 那麼權重不會變。
如果我上的是中字輩，則頂大跟地名的權重會變為 2，中字輩的權重變為 3
如果我上的是地名，則頂大的權重會變為 1，中字輩的權重變為 2，地名變為 3

如果你還猜對了我最後上的是哪間大學，bool 會紀錄為 true
設權重為 w ，你的最後權重將會變為 (w^2)/3
*/

const double wewefoot = 1.35;

inline signed solve(){
    pair<string,pair<int,bool>> data[1005];
    int weight[3] = {3,2,1};
    int current = 0;
    int cnt = 0;
    /* 頂大 == 3 , 中字 == 2 , 地名 == 1*/
    current = nextint();
    while(cin >> data[cnt].f >> data[cnt].s.f >> data[cnt].s.s){
        cnt++;
    }
    if(current == 2) weight[0] = 2, weight[2] = 2 , weight[1] = 3;
    else if(current == 1) weight[0] = 1, weight[2] = 3;
    for(int i = 0;i < cnt ;i++){
        if(data[i].s.f == 3) data[i].s.f += weight[0];
        else if(data[i].s.f == 2) data[i].s.f += weight[1];
        else if(data[i].s.f == 1) data[i].s.f += weight[2];

        if(data[i].s.s) data[i].s.f = (data[i].s.f * (data[i].s.f))/3;
    }

    for(int i = 0;i < cnt;i++){
        for(int j = 0;j < data[i].s.f;j++){
            cout << data[i].f <<"\n";
        }
    }
    return 0;
}

signed main(){
   whitebear;
   /*int t = 0;
    t = nextint();
    while(t--)*/
        solve();
   return 0;
}