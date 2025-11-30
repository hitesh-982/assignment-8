#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *left,*right;
    Node(int v){ val=v; left=right=nullptr; }
};

Node* insertBST(Node* r,int v){
    if(!r) return new Node(v);
    if(v<r->val) r->left=insertBST(r->left,v);
    else if(v>r->val) r->right=insertBST(r->right,v);
    return r;
}

Node* minNode(Node* r){
    while(r->left) r=r->left;
    return r;
}

Node* deleteBST(Node* r,int k){
    if(!r) return r;
    if(k<r->val) r->left = deleteBST(r->left,k);
    else if(k>r->val) r->right = deleteBST(r->right,k);
    else {
        if(!r->left) return r->right;
        if(!r->right) return r->left;
        Node* m=minNode(r->right);
        r->val=m->val;
        r->right = deleteBST(r->right,m->val);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    return 1+max(maxDepth(r->left),maxDepth(r->right));
}

int minDepth(Node* r){
    if(!r) return 0;
    int l=minDepth(r->left), r2=minDepth(r->right);
    if(!l || !r2) return 1+l+r2;
    return 1+min(l,r2);
}

int main(){
    Node* root=nullptr;
    int arr[]={15,10,20,8,12,17,25};
    for(int x:arr) root=insertBST(root,x);

    root = deleteBST(root,20);

    cout<<"Max Depth: "<<maxDepth(root)<<"\n";
    cout<<"Min Depth: "<<minDepth(root)<<"\n";
}
