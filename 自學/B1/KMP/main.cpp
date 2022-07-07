#include <iostream>
using namespace std;

void get_next(string t, int *next){
    int j=0, k=-1;
    next[0]=-1;
    
    while (j<t.length()){
        if (k==-1 || t[j]==t[k]){
            j++, k++;
            cout << "j: " << j << " k: " << k << "\n";
            next[j]=next[k];
        }
        else k=next[k]; // k沒有被更改 QQ

        for (int i=0 ; i<t.size()+1 ; i++){
            cout << next[i] << " ";
        }cout << "\n";
    }
}

int KMP(string s, string t, int *next){
    int i=0, j=0;
    int slen = s.length();
    int tlen = t.length();
    get_next(t, next); // get prefix+suffix in t

    while (i<slen && j<tlen){
        if (j==-1 || s[i]==t[j]) i++, j++;
        else j=next[j];
    }

    if (j>=tlen) return i-tlen+1;
    else return -1;
}

int main(){
    string first_string, second_string;
    int next[100000];
    int *p = next;

    cout << "input 2 string: \n";
    cin >> first_string >> second_string;
    cout << KMP(first_string, second_string, p) << "\n"; // rip temmie, rip pointer

   
    return 0;
}