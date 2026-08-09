// 双链表（数组模拟，哨兵节点版） —— AcWing 827. 双链表
// 0号节点是左哨兵，1号节点是右哨兵，数据节点从下标2开始
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
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

    return 0;
}