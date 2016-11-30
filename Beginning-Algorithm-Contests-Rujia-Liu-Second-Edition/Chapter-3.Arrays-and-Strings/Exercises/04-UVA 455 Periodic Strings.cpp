//created by sfailsthy 2016/10/29 0:09
#include <iostream>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
char str[100];
int n;
bool check(int t)
{
    if((n%t)!=0) return false;
    int d=n/t;
    for(int j=1;j<d;j++){
        for(int i=0;i<t;i++){
            if(str[t*j+i]!=str[i]) return false;
        }
    }
    return true;
}

int solve()
{
    for(int t=1;t<=n;t++){
        if(check(t)) return t;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        n=strlen(str);
        cout<<solve()<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
