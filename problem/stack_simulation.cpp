// AcWing 828. 模拟栈
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int stk[N];
int tt=-1;

void Push(int x){
    stk[++tt]=x;
}

void Pop(){
    tt--;
}

void Query(){
    cout<<stk[tt]<<endl;
}

void Empty(){
    if(tt<0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>m;
    while(m--){
        string a;
        cin>>a;
        if(a=="push"){
            int x;
            cin>>x;
            Push(x);
        }
        else if(a=="pop")Pop();
        else if(a=="empty")Empty();
        else if(a=="query")Query();
        else;
    }
    return 0;
}