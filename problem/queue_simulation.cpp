// AcWing 829. 模拟队列
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int q[N];
int m;
int tt,ww;

void init(){
    tt=0;
    ww=-1;
}

void push(int x){
    q[++ww]=x;
}

void pop(){
    tt++;
}

void empty(){
    if(ww<tt)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return ;
}

void query(){
    cout<<q[tt]<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string opt;
    init();
    cin>>m;
    while(m--){
        cin>>opt;
        if(opt=="push"){
            int x;
            cin>>x;
            push(x);
        }
        else if(opt=="pop")pop();
        else if(opt=="empty")empty();
        else if(opt=="query")query();
        else break;
    }
    return 0;
}