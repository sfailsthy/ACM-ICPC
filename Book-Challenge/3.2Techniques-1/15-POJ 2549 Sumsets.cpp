#include <iostream>
#include <utility>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff

const int maxn =1000+10;
int n;
LL s[maxn];

struct node{
    LL val;
    int i,j;
    node(LL val,int i,int j){
        this->val=val;
        this->i=i;
        this->j=j;
    }

    bool operator < (const node& s) const{
        return val<s.val;
    }

    bool operator > (const node& s) const{
        return val>s.val;
    }

    bool operator != (const node& s) const{
        return i!=s.i&&i!=s.j&&j!=s.i&&j!=s.j;
    }
};



void solve(){
    vector<node> left;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            left.push_back(node(s[i]+s[j],i,j));
        }
    }

    sort(left.begin(),left.end());

    LL res=-INF;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            node s1=node(s[i]-s[j],i,j);
            node s2=node(s[j]-s[i],j,i);
            vector<node>::iterator it1=lower_bound(left.begin(),left.end(),s1);
            if((*it1).val==s1.val){
                if((*it1)!=s1){
                    flag=true;
                    res=max(res,s[s1.i]);
                }
            }

            vector<node>::iterator it2=lower_bound(left.begin(),left.end(),s2);
            if((*it2).val==s2.val){
                if((*it2)!=s2){
                    flag=true;
                    res=max(res,s[s2.i]);
                }
            }
        }
    }

    if(flag) printf("%lld\n",res);
    else printf("no solution\n");
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%lld",&s[i]);
        }
        solve();
    }
    return 0;
}
