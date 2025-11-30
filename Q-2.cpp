#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int v){ val=v; left=right=nullptr; }
};

Node* insertBST(Node* r,int v){
    if(!r) return new Node(v);
    if(v<r->val) r->left = insertBST(r->left,v);
    else r->right = insertBST(r->right,v);
    return r;
}

Node* searchRec(Node* r,int k){
    if(!r || r->val==k) return r;
    return (k<r->val)? searchRec(r->left,k):searchRec(r->right,k);
}

Node* searchNonRec(Node* r,int k){
    while(r && r->val!=k)
        r = (k<r->val)? r->left : r->right;
    return r;
}

Node* minNode(Node* r){
    while(r->left) r=r->left;
    return r;
}

Node* maxNode(Node* r){
    while(r->right) r=r->right;
    return r;
}

Node* successor(Node* root,Node* x){
    if(x->right) return minNode(x->right);
    Node* succ=nullptr;
    while(root){
        if(x->val < root->val){
            succ=root; 
            root=root->left;
        } else root=root->right;
    }
    return succ;
}

Node* predecessor(Node* root,Node* x){
    if(x->left) return maxNode(x->left);
    Node* pre=nullptr;
    while(root){
        if(x->val > root->val){
            pre=root;
            root=root->right;
        } else root=root->left;
    }
    return pre;
}

int main(){
    Node* root=nullptr;
    int arr[]={20,10,5,15,30,25,35};
    for(int x:arr) root=insertBST(root,x);

    Node* s = searchRec(root,15);
    cout<<"Search Rec 15: "<<(s?"Found":"Not Found")<<"\n";

    Node* s2 = searchNonRec(root,30);
    cout<<"Search NonRec 30: "<<(s2?"Found":"Not Found")<<"\n";

    cout<<"Min: "<<minNode(root)->val<<"\n";
    cout<<"Max: "<<maxNode(root)->val<<"\n";

    Node* x = searchRec(root,25);
    cout<<"Successor of 25: "<<successor(root,x)->val<<"\n";
    cout<<"Predecessor of 25: "<<predecessor(root,x)->val<<"\n";
}
