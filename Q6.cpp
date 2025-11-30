#include <iostream>
using namespace std;

int heapArr[100], sz=0;

void push(int x){
    heapArr[sz]=x;
    int i=sz++;
    while(i>0){
        int p=(i-1)/2;
        if(heapArr[p]>=heapArr[i]) break;
        swap(heapArr[p],heapArr[i]);
        i=p;
    }
}

int pop(){
    int t=heapArr[0];
    heapArr[0]=heapArr[sz-1];
    sz--;
    int i=0;
    while(true){
        int l=2*i+1, r=2*i+2, mx=i;
        if(l<sz && heapArr[l]>heapArr[mx]) mx=l;
        if(r<sz && heapArr[r]>heapArr[mx]) mx=r;
        if(mx==i) break;
        swap(heapArr[i],heapArr[mx]);
        i=mx;
    }
    return t;
}

int main(){
    push(10);
    push(40);
    push(20);
    push(30);

    cout<<pop()<<" ";
    cout<<pop()<<" ";
}
