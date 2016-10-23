#include<algorithm>  
#include<cctype>  
#include<cmath>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iomanip>  
#include<iostream>  
#include<map>  
#include<queue>  
#include<string>  
#include<set>  
#include<vector>  
#include<cmath>  
#include<bitset>  
#include<stack>  
#include<sstream>  
#include<deque>  
#include<utility>  
using namespace std;  
#define maxn 2005  
typedef pair<int,int> P;  
  
int m,n;  
int a[maxn][maxn];  
int u[maxn][maxn];  
int l[maxn][maxn],r[maxn][maxn];  
  
void pre()  
{  
    memset(u,0,sizeof(u));  
    for(int i=1;i<=m;i++){  
        for(int j=1;j<=n;j++){  
            if(a[i][j]==0) u[i][j]=0;  
            else u[i][j]=u[i-1][j]+1;  
        }  
    }  
}  
  
void solve()  
{  
    stack<P> s;  
    pre();  
    for(int i=1;i<=m;i++){  
        while(!s.empty()) s.pop();  
        for(int j=1;j<=n;j++){  
            while(!s.empty()&&s.top().first>=u[i][j]){  
                s.pop();  
            }  
            if(s.empty()) l[i][j]=1;  
            else l[i][j]=s.top().second+1;  
            s.push(P(u[i][j],j));  
        }  
    }  
  
    for(int i=1;i<=m;i++){  
        while(!s.empty()) s.pop();  
        for(int j=n;j>=1;j--){  
            while(!s.empty()&&s.top().first>=u[i][j]){  
                s.pop();  
            }  
            if(s.empty()) r[i][j]=m;  
            else r[i][j]=s.top().second-1;  
            s.push(P(u[i][j],j));  
        }  
    }  
  
    int res=0;  
    for(int i=1;i<=m;i++){  
        for(int j=1;j<=n;j++){  
            res=max(res,u[i][j]*(r[i][j]-l[i][j]+1));  
        }  
    }  
    printf("%d\n",res);  
}  
  
int main()  
{  
    while(scanf("%d%d",&m,&n)!=EOF){  
        for(int i=1;i<=m;i++){  
            for(int j=1;j<=n;j++){  
                scanf("%d",&a[i][j]);  
            }  
        }  
        solve();  
    }  
    return 0;  
}  
