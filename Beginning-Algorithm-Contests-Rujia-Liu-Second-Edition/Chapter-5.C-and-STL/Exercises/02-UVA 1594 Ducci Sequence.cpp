//created by sfailsthy 2016/11/9 23:07
/*
受那题集合栈的影响，给每个数组进行编号，对于新数组，如果找到编号，说明是循环，对于ZERO，直接判断即可。
然而TLE，STL实在是太慢了
去搜题解，发现直接枚举1000次就行，改成200次也能AC，时间从130ms降到30ms
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn =20;
int a[maxn];
int n;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        bool flag=false;

        for(int k=0;k<1000;k++){
            int x=a[0];
            for(int i=0;i<n-1;i++){
                a[i]=abs(a[i]-a[i+1]);
            }
            a[n-1]=abs(a[n-1]-x);

            int cnt=0;
            for(int i=0;i<n;i++){
                if(!a[i]){
                    cnt++;
                }
            }

            flag=false;
            if(cnt==n){
                flag=true;
                break;
            }
        }

        if(flag){
            printf("ZERO\n");
        }
        else{
            printf("LOOP\n");
        }
    }
    return 0;
}


///附上STL版的代码，TLE了
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

const int maxn =20;

typedef vector<int> vec;
vector<vec> ans;
map<vec,int> IDvec;

int n;
int a[maxn];

bool ID(vec v){
    if(IDvec.count(v)) return true;
    
    else{
        ans.push_back(v);
        IDvec[v]=ans.size()-1;
        return false;
    }
}

bool check(vec v){
    sort(v.begin(),v.end());

    if(v[0]==0&&v[v.size()-1]==0){
        return true;
    }
    else return false;
}

void solve(){
    for(int i=0;i<ans.size();i++){
        IDvec[ans[i]]=0;
    }

    for(int i=0;i<ans.size();i++){
        ans[i].clear();
    }

    vec v;
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
    }

    ans.push_back(v);
    bool flag=true;

    while(flag){
        v=ans[ans.size()-1];
        if(ID(v)){
            printf("LOOP");
            flag=false;
            return;
        }

        if(check(v)){
            printf("ZERO");
            flag=false;
            return;
        }

        vec v1;
        for(int i=0;i<n-1;i++){
            v1.push_back(abs(v[i]-v[i+1]));
        }
        v1.push_back(abs(v[0]-v[n-1]));
        ans.push_back(v1);

    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        
        solve();
        if(t) printf("\n");
    }
    return 0;
}
