#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int n;
int a[N];
int s[N];
/*
s[i]是记录元素i的重复次数，如果s[i]>=2
那么左指针j往右移直到区间合法
*/
int main(){
    int res=1;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(s[a[i]]>=2){
            s[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}