// 单链表（数组模拟）
// 学习版：h 为头节点下标（h=-1 表示空表），下标充当指针，附带按值查下标
// 题解版：AcWing 826. 单链表
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int ele[N],nex[N],id,h=-1;
int mp[N];
void push_front(int x){
    id++;
    ele[id]=x;
    mp[x]=id;
    nex[id]=nex[h];
    nex[h]=id;
}
void print(){
    for(int i=nex[h];i;i=nex[i]){
        cout<<ele[i]<<' ';
    }
    cout<<endl;
}
int find(int x){
    return mp[x];
}
void insert(int p,int x){
    id++;
    mp[x]=id;
    ele[id]=x;
    nex[id]=nex[p];
    nex[p]=id;
}
void erse(int p){
    if(nex[p]){
        mp[ele[nex[p]]]=0;
        nex[p]=nex[nex[p]];
    }
}

// ========== AcWing 826. 单链表 ==========
// head 为头指针（head=-1 表示空表），idx 为当前可用的下标
int head,idx;
int e[N];
int ne[N];
//初始化
void init(){
    head=-1;
    idx=0;
}
//头插
void aw_push_front(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}
//在下标为k的点的后面添加值为x的节点
void push(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
//删掉下标为k的节点的下一个节点，k<0表示删头节点
void remove(int k){
    if(k<0)head=ne[head];
    else   ne[k]=ne[ne[k]];
}

int main(){
    int m;
    cin>>m;
    init();
    while(m--){
        char a;
        int k;
        int x;
        cin>>a;
        switch(a){
            case 'H':{
                cin>>x;
                aw_push_front(x);
                break;
            }
            case 'D':{
                cin>>k;
                remove(k-1);
                break;
            }
            case 'I':{
                cin>>k>>x;
                push(k-1,x);
                break;
            }
        }
    }
    for(int i=head;i!=-1;i=ne[i]){
        cout<<e[i]<<' ';
    }
    return 0;
}
