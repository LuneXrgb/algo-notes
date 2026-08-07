#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n;
int a[N];
int cnt=1;
vector <pair<int,int>> input;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        input.push_back({l,r});
    }
    sort(input.begin(),input.end());
    pair<int,int> temp=input[0];
    for(int i=1;i<n;i++){
        if(temp.second<input[i].first){
            temp=input[i];
            cnt++;
        }
        else{
            temp.second=max(temp.second,input[i].second);
        }
    }
    cout<<cnt<<endl;
    return 0;
}