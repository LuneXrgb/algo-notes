// AcWing 831. KMP字符串
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int n,m;
char p[N],s[N];
int ne[N];

void init_next(){
    for(int i=2,j=0;i<=n;i++){
        while(j && p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p+1>>m>>s+1;
    init_next();
    for(int i=1,j=0;i<=m;i++){
        while(j && s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            cout<<(i-n+1)-1<<' ';
            j=ne[j];
        }
    }
    return 0;
}