#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int ele[N],nex[N],id,h;
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
int main(){
    for(int i=1;i<=5;i++){
        push_front(i);
        print();
    }
    cout<<find(2)<<endl;
    erse(2);
    print();
    erse(4);
    print();
    return 0;
}