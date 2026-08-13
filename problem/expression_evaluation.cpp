// AcWing 3302. 表达式求值
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
stack <int> num;
stack <char> sigs;
string a;

void eval(){
    int a,b;
    char change=sigs.top();
    sigs.pop();
    b=num.top();
    num.pop();
    a=num.top();
    num.pop();
    switch(change){
        case '+':{
            num.push(a+b);
            break;
        }
        case '-':{
            num.push(a-b);
            break;
        }
        case '*':{
            num.push(a*b);
            break;
        }
        case '/':{
            num.push(a/b);
            break;
        }
    }
}

int pre(char c){
    if(c=='+' || c=='-')return 1;
    else return 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(isdigit(a[i])){
            int cnt=0;
            while(i<a.size() && isdigit(a[i])){
                cnt=cnt*10+a[i]-'0';
                i++;
            }
            num.push(cnt);
            i--;
        }
        else if(a[i]=='(')sigs.push('(');
        else if(a[i]==')'){
            while(sigs.top()!='('){
                eval();
            }
            sigs.pop();
        }
        else{
            while(sigs.size() && sigs.top()!='(' && pre(a[i])<=pre(sigs.top())){
                eval();
            }
            sigs.push(a[i]);
        }
    }
    while(sigs.size())eval();
    cout<<num.top()<<endl;
    return 0;
}