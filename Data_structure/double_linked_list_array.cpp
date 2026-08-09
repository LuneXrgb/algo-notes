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
