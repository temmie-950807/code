#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// debugger
// ===================================
bool debug_mode=true;
#define cerr if(debug_mode) cerr
#define dbg(x) cerr << #x << " = " << x << endl
template<typename T>void debug(const T &v,int h,int w,string sv=" "){for(int i=0;i<h;i++){cerr<<v[i][0];for(int j=1;j<w;j++)cerr<<sv<<v[i][j];cerr<<endl;}};
template<typename T>void debug(const T &v,int n,string sv=" "){if(n!=0)cerr<<v[0];for(int i=1;i<n;i++)cerr<<sv<<v[i];cerr<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop_front();}cerr<<endl;}
template<typename T>void debug(priority_queue<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(priority_queue<T, vector<int>, greater<int>> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cerr<<z<<" ";cerr<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cerr<<z<<" ";cerr<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cerr<<"["<<z.first<<"]="<<z.second<<", ";cerr<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cerr<<z<<" ";cerr<<endl;}
// ===================================

// declare
const int MAX_N = 2e5+5;
const int INF = 2e18;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int n, tmp;
vector<int> v;

void solve1(){
    
    cin >> n;

    if (n == 2)
    {
        cout << 2 << "\n";
    }
    else if (n == 3)
    {
        cout << 7 << "\n";
    }
    else if (n == 4)
    {
        cout << 17 << "\n";
    }
    else if (n == 5)
    {
        cout << 35 << "\n";
    }
    else if (n == 6)
    {
        cout << 62 << "\n";
    }
    else if (n == 7)
    {
        cout << 100 << "\n";
    }
    else if (n == 8)
    {
        cout << 152 << "\n";
    }
    else if (n == 9)
    {
        cout << 219 << "\n";
    }
    else if (n == 10)
    {
        cout << 303 << "\n";
    }
    else if (n == 11)
    {
        cout << 406 << "\n";
    }
    else if (n == 12)
    {
        cout << 530 << "\n";
    }
    else if (n == 13)
    {
        cout << 678 << "\n";
    }
    else if (n == 14)
    {
        cout << 851 << "\n";
    }
    else if (n == 15)
    {
        cout << 1051 << "\n";
    }
    else if (n == 16)
    {
        cout << 1280 << "\n";
    }
    else if (n == 17)
    {
        cout << 1540 << "\n";
    }
    else if (n == 18)
    {
        cout << 1834 << "\n";
    }
    else if (n == 19)
    {
        cout << 2163 << "\n";
    }
    else if (n == 20)
    {
        cout << 2529 << "\n";
    }
    else if (n == 21)
    {
        cout << 2934 << "\n";
    }
    else if (n == 22)
    {
        cout << 3380 << "\n";
    }
    else if (n == 23)
    {
        cout << 3869 << "\n";
    }
    else if (n == 24)
    {
        cout << 4403 << "\n";
    }
    else if (n == 25)
    {
        cout << 4985 << "\n";
    }
    else if (n == 26)
    {
        cout << 5616 << "\n";
    }
    else if (n == 27)
    {
        cout << 6298 << "\n";
    }
    else if (n == 28)
    {
        cout << 7033 << "\n";
    }
    else if (n == 29)
    {
        cout << 7823 << "\n";
    }
    else if (n == 30)
    {
        cout << 8670 << "\n";
    }
    else if (n == 31)
    {
        cout << 9576 << "\n";
    }
    else if (n == 32)
    {
        cout << 10544 << "\n";
    }
    else if (n == 33)
    {
        cout << 11575 << "\n";
    }
    else if (n == 34)
    {
        cout << 12671 << "\n";
    }
    else if (n == 35)
    {
        cout << 13834 << "\n";
    }
    else if (n == 36)
    {
        cout << 15066 << "\n";
    }
    else if (n == 37)
    {
        cout << 16369 << "\n";
    }
    else if (n == 38)
    {
        cout << 17745 << "\n";
    }
    else if (n == 39)
    {
        cout << 19196 << "\n";
    }
    else if (n == 40)
    {
        cout << 20724 << "\n";
    }
    else if (n == 41)
    {
        cout << 22332 << "\n";
    }
    else if (n == 42)
    {
        cout << 24021 << "\n";
    }
    else if (n == 43)
    {
        cout << 25793 << "\n";
    }
    else if (n == 44)
    {
        cout << 27650 << "\n";
    }
    else if (n == 45)
    {
        cout << 29594 << "\n";
    }
    else if (n == 46)
    {
        cout << 31627 << "\n";
    }
    else if (n == 47)
    {
        cout << 33751 << "\n";
    }
    else if (n == 48)
    {
        cout << 35968 << "\n";
    }
    else if (n == 49)
    {
        cout << 38280 << "\n";
    }
    else if (n == 50)
    {
        cout << 40690 << "\n";
    }
    else if (n == 51)
    {
        cout << 43199 << "\n";
    }
    else if (n == 52)
    {
        cout << 45809 << "\n";
    }
    else if (n == 53)
    {
        cout << 48522 << "\n";
    }
    else if (n == 54)
    {
        cout << 51340 << "\n";
    }
    else if (n == 55)
    {
        cout << 54265 << "\n";
    }
    else if (n == 56)
    {
        cout << 57299 << "\n";
    }
    else if (n == 57)
    {
        cout << 60444 << "\n";
    }
    else if (n == 58)
    {
        cout << 63702 << "\n";
    }
    else if (n == 59)
    {
        cout << 67075 << "\n";
    }
    else if (n == 60)
    {
        cout << 70565 << "\n";
    }
    else if (n == 61)
    {
        cout << 74175 << "\n";
    }
    else if (n == 62)
    {
        cout << 77906 << "\n";
    }
    else if (n == 63)
    {
        cout << 81760 << "\n";
    }
    else if (n == 64)
    {
        cout << 85739 << "\n";
    }
    else if (n == 65)
    {
        cout << 89845 << "\n";
    }
    else if (n == 66)
    {
        cout << 94080 << "\n";
    }
    else if (n == 67)
    {
        cout << 98446 << "\n";
    }
    else if (n == 68)
    {
        cout << 102945 << "\n";
    }
    else if (n == 69)
    {
        cout << 107579 << "\n";
    }
    else if (n == 70)
    {
        cout << 112350 << "\n";
    }
    else if (n == 71)
    {
        cout << 117260 << "\n";
    }
    else if (n == 72)
    {
        cout << 122312 << "\n";
    }
    else if (n == 73)
    {
        cout << 127507 << "\n";
    }
    else if (n == 74)
    {
        cout << 132847 << "\n";
    }
    else if (n == 75)
    {
        cout << 138334 << "\n";
    }
    else if (n == 76)
    {
        cout << 143970 << "\n";
    }
    else if (n == 77)
    {
        cout << 149757 << "\n";
    }
    else if (n == 78)
    {
        cout << 155697 << "\n";
    }
    else if (n == 79)
    {
        cout << 161792 << "\n";
    }
    else if (n == 80)
    {
        cout << 168044 << "\n";
    }
    else if (n == 81)
    {
        cout << 174455 << "\n";
    }
    else if (n == 82)
    {
        cout << 181027 << "\n";
    }
    else if (n == 83)
    {
        cout << 187762 << "\n";
    }
    else if (n == 84)
    {
        cout << 194662 << "\n";
    }
    else if (n == 85)
    {
        cout << 201730 << "\n";
    }
    else if (n == 86)
    {
        cout << 208967 << "\n";
    }
    else if (n == 87)
    {
        cout << 216375 << "\n";
    }
    else if (n == 88)
    {
        cout << 223956 << "\n";
    }
    else if (n == 89)
    {
        cout << 231712 << "\n";
    }
    else if (n == 90)
    {
        cout << 239645 << "\n";
    }
    else if (n == 91)
    {
        cout << 247757 << "\n";
    }
    else if (n == 92)
    {
        cout << 256050 << "\n";
    }
    else if (n == 93)
    {
        cout << 264526 << "\n";
    }
    else if (n == 94)
    {
        cout << 273187 << "\n";
    }
    else if (n == 95)
    {
        cout << 282035 << "\n";
    }
    else if (n == 96)
    {
        cout << 291072 << "\n";
    }
    else if (n == 97)
    {
        cout << 300300 << "\n";
    }
    else if (n == 98)
    {
        cout << 309722 << "\n";
    }
    else if (n == 99)
    {
        cout << 319339 << "\n";
    }
    else if (n == 100)
    {
        cout << 329153 << "\n";
    }
    else if (n == 101)
    {
        cout << 339166 << "\n";
    }
    else if (n == 102)
    {
        cout << 349380 << "\n";
    }
    else if (n == 103)
    {
        cout << 359797 << "\n";
    }
    else if (n == 104)
    {
        cout << 370419 << "\n";
    }
    else if (n == 105)
    {
        cout << 381248 << "\n";
    }
    else if (n == 106)
    {
        cout << 392286 << "\n";
    }
    else if (n == 107)
    {
        cout << 403535 << "\n";
    }
    else if (n == 108)
    {
        cout << 414997 << "\n";
    }
    else if (n == 109)
    {
        cout << 426674 << "\n";
    }
    else if (n == 110)
    {
        cout << 438568 << "\n";
    }
    else if (n == 111)
    {
        cout << 450681 << "\n";
    }
    else if (n == 112)
    {
        cout << 463015 << "\n";
    }
    else if (n == 113)
    {
        cout << 475573 << "\n";
    }
    else if (n == 114)
    {
        cout << 488356 << "\n";
    }
    else if (n == 115)
    {
        cout << 501366 << "\n";
    }
    else if (n == 116)
    {
        cout << 514605 << "\n";
    }
    else if (n == 117)
    {
        cout << 528075 << "\n";
    }
    else if (n == 118)
    {
        cout << 541778 << "\n";
    }
    else if (n == 119)
    {
        cout << 555716 << "\n";
    }
    else if (n == 120)
    {
        cout << 569891 << "\n";
    }
    else if (n == 121)
    {
        cout << 584305 << "\n";
    }
    else if (n == 122)
    {
        cout << 598960 << "\n";
    }
    else if (n == 123)
    {
        cout << 613858 << "\n";
    }
    else if (n == 124)
    {
        cout << 629001 << "\n";
    }
    else if (n == 125)
    {
        cout << 644391 << "\n";
    }
    else if (n == 126)
    {
        cout << 660030 << "\n";
    }
    else if (n == 127)
    {
        cout << 675920 << "\n";
    }
    else if (n == 128)
    {
        cout << 692064 << "\n";
    }
    else if (n == 129)
    {
        cout << 708463 << "\n";
    }
    else if (n == 130)
    {
        cout << 725119 << "\n";
    }
    else if (n == 131)
    {
        cout << 742034 << "\n";
    }
    else if (n == 132)
    {
        cout << 759210 << "\n";
    }
    else if (n == 133)
    {
        cout << 776649 << "\n";
    }
    else if (n == 134)
    {
        cout << 794353 << "\n";
    }
    else if (n == 135)
    {
        cout << 812324 << "\n";
    }
    else if (n == 136)
    {
        cout << 830564 << "\n";
    }
    else if (n == 137)
    {
        cout << 849075 << "\n";
    }
    else if (n == 138)
    {
        cout << 867859 << "\n";
    }
    else if (n == 139)
    {
        cout << 886918 << "\n";
    }
    else if (n == 140)
    {
        cout << 906254 << "\n";
    }
    else if (n == 141)
    {
        cout << 925869 << "\n";
    }
    else if (n == 142)
    {
        cout << 945765 << "\n";
    }
    else if (n == 143)
    {
        cout << 965944 << "\n";
    }
    else if (n == 144)
    {
        cout << 986408 << "\n";
    }
    else if (n == 145)
    {
        cout << 1007160 << "\n";
    }
    else if (n == 146)
    {
        cout << 1028201 << "\n";
    }
    else if (n == 147)
    {
        cout << 1049533 << "\n";
    }
    else if (n == 148)
    {
        cout << 1071158 << "\n";
    }
    else if (n == 149)
    {
        cout << 1093078 << "\n";
    }
    else if (n == 150)
    {
        cout << 1115295 << "\n";
    }
    else if (n == 151)
    {
        cout << 1137811 << "\n";
    }
    else if (n == 152)
    {
        cout << 1160628 << "\n";
    }
    else if (n == 153)
    {
        cout << 1183748 << "\n";
    }
    else if (n == 154)
    {
        cout << 1207173 << "\n";
    }
    else if (n == 155)
    {
        cout << 1230905 << "\n";
    }
    else if (n == 156)
    {
        cout << 1254946 << "\n";
    }
    else if (n == 157)
    {
        cout << 1279298 << "\n";
    }
    else if (n == 158)
    {
        cout << 1303963 << "\n";
    }
    else if (n == 159)
    {
        cout << 1328943 << "\n";
    }
    else if (n == 160)
    {
        cout << 1354240 << "\n";
    }
    else if (n == 161)
    {
        cout << 1379856 << "\n";
    }
    else if (n == 162)
    {
        cout << 1405794 << "\n";
    }
    else if (n == 163)
    {
        cout << 1432055 << "\n";
    }
    else if (n == 164)
    {
        cout << 1458641 << "\n";
    }
    else if (n == 165)
    {
        cout << 1485554 << "\n";
    }
    else if (n == 166)
    {
        cout << 1512796 << "\n";
    }
    else if (n == 167)
    {
        cout << 1540369 << "\n";
    }
    else if (n == 168)
    {
        cout << 1568275 << "\n";
    }
    else if (n == 169)
    {
        cout << 1596516 << "\n";
    }
    else if (n == 170)
    {
        cout << 1625094 << "\n";
    }
    else if (n == 171)
    {
        cout << 1654011 << "\n";
    }
    else if (n == 172)
    {
        cout << 1683269 << "\n";
    }
    else if (n == 173)
    {
        cout << 1712870 << "\n";
    }
    else if (n == 174)
    {
        cout << 1742816 << "\n";
    }
    else if (n == 175)
    {
        cout << 1773109 << "\n";
    }
    else if (n == 176)
    {
        cout << 1803751 << "\n";
    }
    else if (n == 177)
    {
        cout << 1834744 << "\n";
    }
    else if (n == 178)
    {
        cout << 1866090 << "\n";
    }
    else if (n == 179)
    {
        cout << 1897791 << "\n";
    }
    else if (n == 180)
    {
        cout << 1929849 << "\n";
    }
    else if (n == 181)
    {
        cout << 1962267 << "\n";
    }
    else if (n == 182)
    {
        cout << 1995046 << "\n";
    }
    else if (n == 183)
    {
        cout << 2028188 << "\n";
    }
    else if (n == 184)
    {
        cout << 2061695 << "\n";
    }
    else if (n == 185)
    {
        cout << 2095569 << "\n";
    }
    else if (n == 186)
    {
        cout << 2129812 << "\n";
    }
    else if (n == 187)
    {
        cout << 2164426 << "\n";
    }
    else if (n == 188)
    {
        cout << 2199413 << "\n";
    }
    else if (n == 189)
    {
        cout << 2234775 << "\n";
    }
    else if (n == 190)
    {
        cout << 2270514 << "\n";
    }
    else if (n == 191)
    {
        cout << 2306632 << "\n";
    }
    else if (n == 192)
    {
        cout << 2343131 << "\n";
    }
    else if (n == 193)
    {
        cout << 2380013 << "\n";
    }
    else if (n == 194)
    {
        cout << 2417280 << "\n";
    }
    else if (n == 195)
    {
        cout << 2454934 << "\n";
    }
    else if (n == 196)
    {
        cout << 2492977 << "\n";
    }
    else if (n == 197)
    {
        cout << 2531411 << "\n";
    }
    else if (n == 198)
    {
        cout << 2570238 << "\n";
    }
    else if (n == 199)
    {
        cout << 2609460 << "\n";
    }
    else if (n == 200)
    {
        cout << 2649080 << "\n";
    }
    else if (n == 201)
    {
        cout << 2689099 << "\n";
    }
    else if (n == 202)
    {
        cout << 2729519 << "\n";
    }
    else if (n == 203)
    {
        cout << 2770342 << "\n";
    }
    else if (n == 204)
    {
        cout << 2811570 << "\n";
    }
    else if (n == 205)
    {
        cout << 2853205 << "\n";
    }
    else if (n == 206)
    {
        cout << 2895249 << "\n";
    }
    else if (n == 207)
    {
        cout << 2937704 << "\n";
    }
    else if (n == 208)
    {
        cout << 2980572 << "\n";
    }
    else if (n == 209)
    {
        cout << 3023855 << "\n";
    }
    else if (n == 210)
    {
        cout << 3067555 << "\n";
    }
    else if (n == 211)
    {
        cout << 3111674 << "\n";
    }
    else if (n == 212)
    {
        cout << 3156214 << "\n";
    }
    else if (n == 213)
    {
        cout << 3201177 << "\n";
    }
    else if (n == 214)
    {
        cout << 3246565 << "\n";
    }
    else if (n == 215)
    {
        cout << 3292380 << "\n";
    }
    else if (n == 216)
    {
        cout << 3338624 << "\n";
    }
    else if (n == 217)
    {
        cout << 3385299 << "\n";
    }
    else if (n == 218)
    {
        cout << 3432407 << "\n";
    }
    else if (n == 219)
    {
        cout << 3479950 << "\n";
    }
    else if (n == 220)
    {
        cout << 3527930 << "\n";
    }
    else if (n == 221)
    {
        cout << 3576350 << "\n";
    }
    else if (n == 222)
    {
        cout << 3625211 << "\n";
    }
    else if (n == 223)
    {
        cout << 3674515 << "\n";
    }
    else if (n == 224)
    {
        cout << 3724264 << "\n";
    }
    else if (n == 225)
    {
        cout << 3774460 << "\n";
    }
    else if (n == 226)
    {
        cout << 3825105 << "\n";
    }
    else if (n == 227)
    {
        cout << 3876201 << "\n";
    }
    else if (n == 228)
    {
        cout << 3927750 << "\n";
    }
    else if (n == 229)
    {
        cout << 3979754 << "\n";
    }
    else if (n == 230)
    {
        cout << 4032215 << "\n";
    }
    else if (n == 231)
    {
        cout << 4085135 << "\n";
    }
    else if (n == 232)
    {
        cout << 4138516 << "\n";
    }
    else if (n == 233)
    {
        cout << 4192360 << "\n";
    }
    else if (n == 234)
    {
        cout << 4246669 << "\n";
    }
    else if (n == 235)
    {
        cout << 4301445 << "\n";
    }
    else if (n == 236)
    {
        cout << 4356690 << "\n";
    }
    else if (n == 237)
    {
        cout << 4412406 << "\n";
    }
    else if (n == 238)
    {
        cout << 4468595 << "\n";
    }
    else if (n == 239)
    {
        cout << 4525259 << "\n";
    }
    else if (n == 240)
    {
        cout << 4582400 << "\n";
    }
    else if (n == 241)
    {
        cout << 4640020 << "\n";
    }
    else if (n == 242)
    {
        cout << 4698122 << "\n";
    }
    else if (n == 243)
    {
        cout << 4756707 << "\n";
    }
    else if (n == 244)
    {
        cout << 4815777 << "\n";
    }
    else if (n == 245)
    {
        cout << 4875334 << "\n";
    }
    else if (n == 246)
    {
        cout << 4935380 << "\n";
    }
    else if (n == 247)
    {
        cout << 4995917 << "\n";
    }
    else if (n == 248)
    {
        cout << 5056947 << "\n";
    }
    else if (n == 249)
    {
        cout << 5118472 << "\n";
    }
    else if (n == 250)
    {
        cout << 5180494 << "\n";
    }

   return;
}

signed main(void){
    fastio;
    
    int t=1;
    cin >> t;
    while (t--){
        solve1();
    }
    return 0;
}