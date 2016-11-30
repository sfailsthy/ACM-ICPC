//created by sfailsthy 2016/11/25 22:55
/*
这题很快就想到了正确解法，却写了好长时间，代码能力还是很差。。。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> node;

const int maxn =1e5+10;
bool is_prime[maxn];

void sieve(){
    for(int i=0;i<=maxn;i++){
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;

    for(int i=2;i<=maxn;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=maxn;j+=i){
                is_prime[j]=false;
            }
        }
    }
}

bool mark[maxn];

int bfs(int n,int m){
    memset(mark,0,sizeof(mark));

    queue<node> que;
    node start=node(n,0);
    mark[n]=1;
    que.push(start);

    while(!que.empty()){
        node node1=que.front();
        que.pop();

        int x=node1.first,nx;
        //cout<<x<<endl;
        if(x==m){
            return node1.second;
        }

        for(int i=1;i<=9;i++){
            nx=1000*i+x%1000;
            if(nx!=x&&is_prime[nx]&&!mark[nx]){
                //cout<<nx<<endl;
                mark[nx]=1;
                que.push(node(nx,node1.second+1));
            }
        }


        for(int i=0;i<=9;i++){
            nx=1000*(x/1000)+100*i+x%100;
            if(nx!=x&&is_prime[nx]&&!mark[nx]){
                //cout<<nx<<endl;
                mark[nx]=1;
                que.push(node(nx,node1.second+1));
            }
        }

        for(int i=0;i<=9;i++){
            nx=x-x%100+10*i+x%10;
            if(nx!=x&&is_prime[nx]&&!mark[nx]){
                //cout<<nx<<endl;
                mark[nx]=1;
                que.push(node(nx,node1.second+1));
            }
        }


        for(int i=0;i<=9;i++){
            nx=10*(x/10)+i;
            if(nx!=x&&is_prime[nx]&&!mark[nx]){
                //cout<<nx<<endl;
                mark[nx]=1;
                que.push(node(nx,node1.second+1));
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    sieve();
    while(t--){
        cin>>n>>m;
        cout<<bfs(n,m)<<endl;
    }
    return 0;
}
