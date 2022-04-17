#include <iostream>
using namespace std;

typedef struct Bnode
{
    int data;
    Bnode *lchild, *rchild;
} Bnode;

void Create_Tree(Bnode **T)
{
    char check; // 確認是否創建節點
    *T = new Bnode;
    cout << *T << "\n";
    cout << "輸入節點的值: \n";
    cin >> (*T)->data;

    cout << "是否增加" << (*T)->data << "的左節點? (Y/N)\n"; // 增加左節點
    cin >> check;
    if (check == 'Y')
        Create_Tree(&(*T)->lchild);
    else
        (*T)->lchild = NULL;

    cout << "是否增加" << (*T)->data << "的右節點? (Y/N)\n"; // 增加右節點
    cin >> check;
    if (check == 'Y')
        Create_Tree(&(*T)->rchild);
    else
        (*T)->rchild = NULL;
}

void preorder(Bnode *T)
{
    if (T)
    {
        cout << T->data << "\n";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

int main()
{
    Bnode *k;
    Create_Tree(&k); // 開始創建二元樹

    // 先序歷遍
    preorder(k);
    return 0;
}