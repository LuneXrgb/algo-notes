#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
vector <pair<int,int>> all,query;
vector <int> indx;
int a[N];
int s[N];

int find(int x){
    int l=0;
    int r=indx.size()-1;
    while(l<r){
        int mid=(l+r)/2;
        if(indx[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r;
}

int main(){
    int n,m;
    cin>>n>>m;
    while(n--){
        int x,c;
        cin>>x>>c;
        all.push_back({x,c});
        indx.push_back(x);
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        indx.push_back(l);
        indx.push_back(r);
    }
    sort(indx.begin(),indx.end());
    indx.erase(unique(indx.begin(),indx.end()),indx.end());
    indx.insert(indx.begin(),0);
    for(auto& p : all){
        a[find(p.first)]+=p.second;
    }
    for(int i=1;i<=indx.size();i++){
        s[i]=s[i-1]+a[i];
    }
    for(auto& q : query){
        int L=find(q.first);
        int R=find(q.second);
        cout<<s[R]-s[L-1]<<endl;
    }
    return 0;
}