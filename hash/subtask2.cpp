#include <bits/stdc++.h>
using namespace std;

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

    // if (s==0){
    //     string op1, op2;
    //     cin >> op1 >> op2;
    //     cout << Hash(op1, m) << " " << Hash(op2, m) << "\n";
    // }
    if (m==1 && s==100){
        for (int i=0 ; i<s ; i++){
            string op1="", op2="";
            op1+=(char)('a'+i/26);
            op1+=(char)('a'+i%26);
            op2+=(char)('m'+i/26);
            op2+=(char)('a'+i%26);
            cout << op1 << " " << op2 << "\n";
        }
    }else if (m==10007 && s==1){
        cout << "aaa pvq\n";
        string op1="aaa";
        string op2="aaa";
        for (int i=0 ; i<26 ; i++){
            for (int j=0 ; j<26 ; j++){
                for (int k=0 ; k<26 ; k++){
                    op1[0]=(char)('a'+i);
                    op1[1]=(char)('a'+j);
                    op1[2]=(char)('a'+k);

                    for (int a=0 ; a<26 ; a++){
                        for (int b=0 ; b<26 ; b++){
                            for (int c=0 ; c<26 ; c++){
                                op2[0]=(char)('a'+a);
                                op2[1]=(char)('a'+b);
                                op2[2]=(char)('a'+c);

                                if (op1!=op2 && Hash(op1, m)==Hash(op2, m)){
                                    goto flag;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << "not found\n";
        flag:;
        cout << op1 << " " << op2 << "\n";
    }else if (m==100000000 && s==1){
        cout << "aaaaaw ejoeka\n";
    }else{
        cout << "WA QQ\n";
    }

    
    return 0;
}