// 单链表（数组模拟） —— AcWing 826. 单链表
// 用 e[] 存值、ne[] 存 next 指针（存的是下标），下标充当指针
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int head,idx;
int e[N];
int ne[N];
//初始化
void init(){
    head=-1;
    idx=0;
}
//头插
void push_front(int x){
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
                push_front(x);
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
