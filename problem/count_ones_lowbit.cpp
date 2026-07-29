#include <bits/stdc++.h>

using namespace std;

int lowbit(int x){
    return x & -x;
}

int main(){
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        int cnt=0;
        while(x>0){
            x-=lowbit(x);
            cnt++;
        }
        cout<<cnt<<' ';
    }
    return 0;
}