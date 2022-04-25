#include <iostream>
using namespace std;

struct Bnode{
    int data;
    Bnode *lchild, *rchild;
};

void CreateTree(Bnode *T){
    char check;

    cout << "請輸入數字: \n";
    cin >> T->data;

    cout << "是否要增加" << T->data << "的左節點?(Y/N)\n";
    cin >> check;
    if (check == 'Y'){
        Bnode *N = new Bnode;
        T->lchild=N;
        CreateTree(N);
    }else{
        T->lchild=NULL;
    }

    cout << "是否要增加" << T->data << "的右節點?(Y/N)\n";
    cin >> check;
    if (check == 'Y'){
        Bnode *N = new Bnode;
        T->rchild=N;
        CreateTree(N);
    }else{
        T->rchild=NULL;
    }
}

void preorder(Bnode *p){
    cout << p->data << "\n";
    if (p->lchild != NULL) preorder(p->lchild);
    if (p->rchild != NULL) preorder(p->rchild);
}

int main(){
    Bnode T;
    CreateTree(&T);
    preorder(&T);
    return 0;
}