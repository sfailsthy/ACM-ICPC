//created by sfailsthy 2016/11/5 15:35
#include <iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;

const int maxn =20+10;
int A[maxn];
int vis[maxn];
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool is_prime(int x)
{
    for(int i=0;i<15;i++){
        if(prime[i]==x) return true;
    }
    return false;
}

void dfs(int cur)
{
    if(cur==n&&is_prime(A[0]+A[cur-1])){
        for(int i=0;i<n-1;i++){
            cout<<A[i]<<" ";
        }
        cout<<A[n-1]<<endl;
    }
    else{
        for(int i=2;i<=n;i++){
            if(!vis[i]&&is_prime(i+A[cur-1])){
                A[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int kase=0;
    while(cin>>n){
        if(kase) cout<<endl;
        cout<<"Case "<<++kase<<":"<<endl;
        memset(vis,0,sizeof(vis));
        A[0]=1;
        dfs(1);
        
    }
    return 0;
}
