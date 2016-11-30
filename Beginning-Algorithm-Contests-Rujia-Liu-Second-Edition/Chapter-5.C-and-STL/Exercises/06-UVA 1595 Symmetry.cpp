//created by sfailsthy 2016/11/5 2:11
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef pair<int,int> P;
const int maxn =1000+10;
const int maxy=10000+10;

map<int,vector<int> >m;
int y[maxn];
int n;

bool check(vector<int> &v)
{
    int len=v.size();
    sort(v.begin(),v.end());
    if(len&1){
        for(int i=0;i<len/2;i++){
            if((v[i]+v[len-1-i])!=2*v[len/2]) return false;
        }
        return true;
    }
    else{
        for(int i=1;i<len/2;i++){
            if((v[i]+v[len-1-i])!=(v[0]+v[len-1])) return false;
        }
        return true;
    }
}

int mid(vector<int> &v)
{
    int len=v.size();
    if(len&1){
        return v[len/2];
    }
    else{
        return (v[0]+v[len-1])/2;
    }
}

void solve()
{
    for(int i=0;i<n;i++){
        if(!check(m[y[i]])){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=1;i<n;i++){
        if(mid(m[y[i]])!=mid(m[y[0]])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        for(int i=-maxy;i<=maxy;i++){
            m[i].clear();
        }
        cin>>n;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            m[b].push_back(a);
            y[i]=b;
        }
        solve();
    }
    return 0;
}
