#include <bits/stdc++.h>
using namespace std;

// debug 工具
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}

string s; // 題目的輸入
stack<int> A; // 維護最近的數字
stack<char> B; // 維護最近的操作

// 將之前為+的所有數值計算起來，並重新丟回A裡面
void add(){
    if (B.size() && B.top()=='+'){
        // 如果最前面的是 + 的話，就先紀錄第一個值
        int total=A.top();
        A.pop();
        while (B.size() && B.top()=='+'){
            // 接著不斷的把所有是 + 的值都加在 total 裡面
            total+=A.top();
            A.pop();
            B.pop();
        }

        // 紀錄該值
        A.push(total);
    }
}

// 將之前前為*的所有數值計算起來，並重新丟回A裡面
void multi(){
    if (B.size() && B.top()=='*'){
        int total=A.top();
        A.pop();
        while (B.size() && B.top()=='*'){
            total*=A.top();
            A.pop();
            B.pop();
        }
        A.push(total);
    }
}

// 將之前為 f() 內的數值計算出來，並重新丟回A裡面
void f(){
    int mi=A.top(), ma=A.top();
    A.pop();
    if (B.size() && B.top()==','){
        while (B.size() && B.top()==','){
            mi=min(mi, A.top());
            ma=max(ma, A.top());
            A.pop();
            B.pop();
        }
    }
    A.push(ma-mi);
}

int main(){
    // 宣告 & 初始化
    int now=0; // 目前的數字總和，以儲存在字串裡找到的數字
    bool flag=0; // 如果 now 裡面有儲存數字的話就計為 1，否則為 0

    // 輸入
    cin >> s;

    // 一一解析所有字元，其中'f'字元不會被使用
    for (int i=0 ; i<s.size() ; i++){
        if ('0'<=s[i] && s[i]<='9'){
            // 如果 s[i] 是數字，就更新 now 和 flag
            now=10*now+s[i]-'0';
            flag=1;

        }else{
            // 如果 flag 等於 1 就代表數字已經被紀錄完畢，因此丟進 A 裡面
            if (flag==1){
                A.push(now);
                flag=0;
                now=0;
            }

            // + 是最高優先級的符號，直接丟進 B 裡面就好
            if (s[i]=='+'){
                B.push('+');
            }

            // * 是次高優先級的符號，因此先把先前所有 + 處理完畢後再丟進去
            //（也就是說前面的數字不會再有任何需要 + 的運算，可以直接和後面的數字做相乘）
            if (s[i]=='*'){
                add();
                B.push('*');
            }

            // , 是用來分隔 f() 裡的所有數字，因此把先前所有的 + * 處理完畢就可以得到可以作為後續比較的數字
            if (s[i]==','){
                add();
                multi();
                B.push(',');
            }

            // 將 ( 紀錄，以免多個 , 被混在一起
            // ex: f(1, 2, f(4, 5, 6))

            // 不加上這段：不知道哪個數字在哪個區段
            //   A: 1 2 4 5 6
            //   B: , , , ,
            
            // 加上這段：可以知道 4 5 6 是一起的
            //   A: 1 2 4 5 6
            //   B: , , ( , ,
            
            if (s[i]=='('){
                B.push('(');
            }

            // 求得最後沒有被處理的數字，最後求得 f() 的結果
            if (s[i]==')'){
                add();
                multi();
                f();

                // 因為前面用了 ( 分隔其他符號，所以這裡要 pop 掉
                B.pop();
            }
        }

        // 你可以在這裡取消註解觀察 stack 的數值
        // debug(A);
        // debug(B);
    }

    // 求得最後沒有被處理的數字
    if (flag==1){
        A.push(now);
        now=0;
        flag=0;
    }
    add();
    multi();

    // 輸出
    cout << A.top() << endl;

    return 0;
}