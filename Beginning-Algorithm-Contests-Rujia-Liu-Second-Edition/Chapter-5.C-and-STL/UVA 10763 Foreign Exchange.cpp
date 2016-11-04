//created by sfailsthy 2016/11/5 1:25
//貌似map经常和set一起用……？
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>
#include<map>
#include<set>
using namespace std;
typedef pair<int,int> P;
const int maxn =500000+10;

P p[maxn];
map<P,int> m;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(cin>>n&&n){
        set<P> s;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            p[i]=make_pair(a,b);
            if(!s.count(p[i])){
                m[p[i]]=0;
                s.insert(p[i]);
            }
            m[p[i]]++;
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            int a=p[i].first,b=p[i].second;
            if(m[p[i]]!=m[make_pair(b,a)]){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
