#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int son[N][26];
int cnt[N];
int idx;

void insert(char* str){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}

int find(char* str){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        p=son[p][u];
    }
    return cnt[p];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>m;
    while(m--){
        char a;
        char str[N];
        cin>>a>>str;
        if(a=='I')insert(str);
        else if(a=='Q')cout<<find(str)<<endl;
    }
    return 0;
}