#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

const int N=3100005;
int son[N][2];
int idx;

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int bit=(x>>i)&1;
        if(!son[p][bit])son[p][bit]=++idx;
        p=son[p][bit];
    }
}

int Xor(int x){
    int p=0,res=0;
    for(int i=30;i>=0;i--){
        int bit=(x>>i)&1;
        if(son[p][!bit]){
            p=son[p][!bit];
            res+=1<<i;
        }
        else p=son[p][bit];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> answer;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(x);
        answer.push_back(Xor(x));
    }
    sort(answer.begin(),answer.end());
    cout<<answer.back()<<endl;
    return 0;
}