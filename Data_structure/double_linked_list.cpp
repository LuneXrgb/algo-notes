#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ele[N],nex[N],pre[N],h,id;
int mp[N];
void push_front(int x){
    id++;
    ele[id]=x;
    mp[x]=id;
    pre[id]=h;
    nex[id]=nex[h];
    pre[nex[id]]=id;
    nex[h]=id;
}
void print(){
    for(int i=nex[h];i;i=nex[i]){
        cout<<ele[i]<<' ';
    }
    cout<<endl<<endl;
}
int find(int x){
    return mp[x];
}
//在p后面插入一个值为x的元素
void insert(int p,int x){
    id++;
    ele[id]=x;
    mp[x]=id;
    pre[id]=p;
    nex[id]=nex[p];
    pre[nex[p]]=id;
    nex[p]=id;
}
//在位置p前面插入一个值为x的元素
void insert_front(int p,int x){
    id++;
    ele[id]=x;
    mp[x]=id;
    pre[id]=pre[p];
    nex[id]=p;
    pre[p]=id;
    nex[pre[id]]=id;
}
void erase(int p){
    mp[ele[p]]=0;
    nex[pre[p]]=nex[p];
    pre[nex[p]]=pre[p];
}
int main(){
    for(int i=1;i<=5;i++){
        push_front(i);
    }
    print();
    insert(2,1145);
    print();
    insert(4,30);
    print();
    return 0;
}