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
using namespace std;  
#define INF 0x7fffffff  
const int maxn=100005;  
  
typedef long long ll;  
  
struct node  
{  
    ll val;  
    ll left,right,sum;  
    node(ll left,ll right,ll val,ll sum){  
        this->left=left;  
        this->right=right;  
        this->val=val;  
        this->sum=sum;  
    }  
};  
int n;  
int a[maxn];  
  
void solve()  
{  
    ll ans=0,ansl=1,ansr=1;  
    stack<node> s;  
    for(int i=0;i<n;i++){  
        ll sums=0;  
        ll left=i;  
        while(!s.empty()&&s.top().val>=a[i]){  
            sums+=s.top().sum;  
            left=s.top().left;  
            if(sums*s.top().val>ans){  
                ans=sums*s.top().val;  
                ansl=s.top().left;  
                ansr=i-1;  
            }  
            s.pop();  
        }  
        s.push(node(left,i,a[i],sums+a[i]));  
    }  
    cout<<ans<<endl<<ansl+1<<" "<<ansr+1<<endl;  
}  
int main()  
{  
    while(scanf("%d",&n)!=EOF&&n){  
        for(int i=0;i<n;i++){  
            scanf("%d",&a[i]);  
        }  
        a[n++]=0;  
        solve();  
    }  
    return 0;  
}  
//////////////////////////////////////////////////

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
using namespace std;  
#define INF 0x7fffffff  
const int maxn=100005;  
  
typedef long long ll;  
  
struct node  
{  
    ll val;  
    ll left,right;  
    node(ll left,ll right,ll val){  
        this->left=left;  
        this->right=right;  
        this->val=val;  
    }  
};  
int n;  
int a[maxn];  
int L[maxn],R[maxn];  
  
ll pre[maxn];  
  
void solve()  
{  
    //前缀和，预处理区间和  
    pre[0]=a[0];  
    for(int i=1;i<n;i++){  
        pre[i]=pre[i-1]+a[i];  
    }  
  
    //求左边的延伸值  
    ll ans=0,ansl=1,ansr=1;  
    stack<node> s;  
    for(int i=0;i<n;i++){  
        //ll sums=0;  
        ll left=i;  
        while(!s.empty()&&s.top().val>=a[i]){  
            //sums+=s.top().sum;  
            left=s.top().left;  
            /*if(sums*s.top().val>ans){ 
                ans=sums*s.top().val; 
                ansl=s.top().left; 
                //ansr=i-1; 
            }*/  
            s.pop();  
        }  
        L[i]=left;  
        s.push(node(left,i,a[i]));  
    }  
  
    while(!s.empty()){  
        s.pop();  
    }  
      
    //求右边的延伸值  
    for(int i=n-1;i>=0;i--){  
        //ll sums=0;  
        ll right=i;  
        while(!s.empty()&&s.top().val>=a[i]){  
            //sums+=s.top().sum;  
            right=s.top().right;  
            /*if(sums*s.top().val>ans){ 
                ans=sums*s.top().val; 
                ansr=s.top().right; 
            }*/  
            s.pop();  
        }  
        R[i]=right;  
        s.push(node(i,right,a[i]));  
    }  
  
    for(int i=0;i<n;i++){  
        /*for(int j=L[i];j<=R[i];j++){ 
            res+=a[i]*a[j]; 
        }*/  
        //直接求会TLE  
        ll res=a[i]*(pre[R[i]]-pre[L[i]-1]);  
        if(res>ans){  
            ans=res;  
            ansl=L[i];  
            ansr=R[i];  
        }  
    }  
    cout<<ans<<endl<<ansl+1<<" "<<ansr+1<<endl;  
}  
int main()  
{  
    while(scanf("%d",&n)!=EOF&&n){  
        for(int i=0;i<n;i++){  
            scanf("%d",&a[i]);  
        }  
        a[n++]=0;  
        solve();  
    }  
    return 0;  
}  
