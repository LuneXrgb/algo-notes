#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m,x;
int a[N];
int b[N];

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int j=m-1,i=0;j>=0 && i<n;j--){
        while(i<n-1 && a[i]+b[j] < x)i++;
        if(a[i]+b[j] > x)continue;
        else if(a[i]+b[j] == x){
            cout<<i<<' '<<j<<endl;
            break;
        }
        else continue;
    }
    return 0;
}