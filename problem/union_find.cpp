#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int p[N];
int n;

void init(){
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
}

int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

void merge(int a,int b){
    p[find(a)]=find(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>m;
    init();
    while(m--){
        char a;
        int op[2];
        cin>>a>>op[0]>>op[1];
        if(a=='M'){
            merge(op[0],op[1]);
        }
        else{
            if(find(op[0])==find(op[1])){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
    }
    return 0;
}