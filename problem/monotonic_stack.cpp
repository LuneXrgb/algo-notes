// AcWing 830. 单调栈
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int stk[N];
int hd;

void init(){
    hd=-1;
}

void push(int x){
    stk[++hd]=x;
}

void pop(){
    hd--;
}

bool empty(){
    if(hd>=0)return false;
    else return true;
}

int top(){
    return stk[hd];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(empty()){
            cout<<-1<<' ';
            push(x);
            continue;
        }
        if(x>top()){
            cout<<top()<<' ';
            push(x);
        }
        else{
            while(!empty() && top()>=x){
                pop();
            } 
            if(!empty())cout<<top()<<' ';
            else cout<<-1<<' ';
            push(x);
        }
    } 
    return 0;
}
