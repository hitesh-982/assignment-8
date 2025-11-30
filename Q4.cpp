#include <iostream>
using namespace std;

struct Node{
    int v;
    Node *l,*r;
    Node(int x){ v=x; l=r=nullptr; }
};

bool isBST(Node* r,int mn,int mx){
    if(!r) return true;
    if(r->v<=mn || r->v>=mx) return false;
    return isBST(r->l,mn,r->v) && isBST(r->r,r->v,mx);
}

int main(){
    Node* root=new Node(10);
    root->l=new Node(5);
    root->r=new Node(20);
    root->l->l=new Node(2);
    root->l->r=new Node(7);

    cout<<(isBST(root,-1e9,1e9)?"BST":"Not BST")<<"\n";
}
