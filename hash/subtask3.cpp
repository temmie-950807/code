#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

uint64_t Hash(const string &s, uint64_t mod) {
    uint64_t val = 0;
    for (char c : s){
        val = (val * 131 + c) % mod;
    }
    return val;
}

int main(){

    // input
    int m, s;
    cin >> m >> s;

    if (s==0){
        string op1, op2;
        cin >> op1 >> op2;
        cout << Hash(op1, m) << " " << Hash(op2, m) << "\n";
    }else if (m==1000000007 && s==1){
        gp_hash_table<int, int, custom_hash> cnt;
        string op1="aaaaaa", op2="aaaaaa";
        for (int a=0 ; a<26 ; a++){
            for (int b=0 ; b<26 ; b++){
                for (int c=0 ; c<26 ; c++){
                    for (int d=0 ; d<26 ; d++){
                        for (int e=0 ; e<26 ; e++){
                            for (int f=0 ; f<26 ; f++){
                                op2[0]=(char)('a'+a);
                                op2[1]=(char)('a'+b);
                                op2[2]=(char)('a'+c);
                                op2[3]=(char)('a'+d);
                                op2[4]=(char)('a'+e);
                                op2[5]=(char)('a'+f);
                                cnt[Hash(op2, m)]++;
                                if (cnt[Hash(op2, m)]==2){
                                    cout << op2 << "\n";
                                    goto flag;
                                }

                                if (Hash(op2, m)==996704364){
                                    cout << op2 << "\n";
                                    goto flag;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << "not found\n";
        return 0;
        flag:;
        cout << op1 << " " << op2 << "\n";
    }else{
        cout << "WA QQ\n";
    }

    
    return 0;
}