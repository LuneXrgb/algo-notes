#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m;
int a[N];
int b[N];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int j=0;
    for(int i=0;i<m;i++){
        if(a[j]==b[i] && j<n){
            j++;
        }
    }
    if(j==n)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}