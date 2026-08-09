// 双链表（数组模拟）
// 学习版：h=0 为头节点（0 下标充当哨兵），附带按值查下标
// 题解版：AcWing 827. 双链表（0 号节点是左哨兵，1 号节点是右哨兵，数据节点从下标 2 开始）
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

// ========== AcWing 827. 双链表 ==========
int l[N],r[N],e[N];
int idx;

void init(){
    r[0]=1;
    l[1]=0;
    idx=2;
}

void push_right(int k,int x){
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    r[k]=idx;
    l[r[idx]]=idx;
    idx++;
}

void push_left(int k,int x){
    push_right(l[k],x);
}
//删除下标为k的点
void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main(){
    init();
    int m;
    cin>>m;
    while(m--){
        char choice;
        cin>>choice;
        int k,x;
        switch(choice){
            case 'L':{
                cin>>x;
                push_right(0,x);
                break;
            }
            case 'R':{
                cin>>x;
                push_left(1,x);
                break;
            }
            case 'D':{
                cin>>k;
                remove(k+1);
                break;
            }
            case 'I':{
                char anotherchoice;
                cin>>anotherchoice;
                switch(anotherchoice){
                    case 'L':{
                        cin>>k>>x;
                        push_left(k+1,x);
                        break;
                    }
                    case 'R':{
                        cin>>k>>x;
                        push_right(k+1,x);
                        break;
                    }
                }
            }
        }
    }
    for(int i=r[0];i!=1;i=r[i]){
        cout<<e[i]<<' ';
    }
    return 0;
}
