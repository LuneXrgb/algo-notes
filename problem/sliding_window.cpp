// AcWing 154. 滑动窗口
#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int que[N];
int hh,tt;
int a[N];

void init(){
    hh=0;
    tt=-1;
}

void push(int x){
    que[++tt]=x;
}

void pop(){
    hh++;
}

int tail(){
    return que[tt];
}

int head(){
    return que[hh];
}

bool empty(){
    return hh>tt;
}

int size(){
    return tt-hh+1;
}

void pop_back(){
    tt--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    init();
    //遍历窗口的右端点
    for(int i=0;i<n;i++){
        if(!empty() && head()<i-k+1){
            pop();
        }
        if(!empty() && a[i]>a[tail()])push(i);
        else{
            while(!empty() && a[i]<=a[tail()]){
                pop_back();
            }
            push(i);
        }
        if(i>=k-1)cout<<a[head()]<<' ';
    }
    cout<<endl;
    init();
    //遍历窗口的右端点
    for(int i=0;i<n;i++){
        if(!empty() && head()<i-k+1){
            pop();
        }
        if(!empty() && a[i]<a[tail()])push(i);
        else{
            while(!empty() && a[i]>=a[tail()]){
                pop_back();
            }
            push(i);
        }
        if(i>=k-1)cout<<a[head()]<<' ';
    }
    return 0;
}