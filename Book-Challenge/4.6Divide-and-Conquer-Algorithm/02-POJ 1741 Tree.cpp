//created by sfailsthy 2016/12/1 23:44
#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn =10000+10;
#define INF 0x3f3f3f3f

struct edge{
    int to,length;
};
vector<edge> G[maxn];
int n,k;
bool centroid[maxn];//顶点是否已作为重心删除的标记
int subtree_size[maxn];//以该顶点为根的子树的大小(查找重心时用)
int ans;//答案

//计算子树大小(subtree_size)的递归函数
int compute_subtree_size(int v,int p){
    int c=1;
    for(int i=0;i<G[v].size();i++){
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        c+=compute_subtree_size(G[v][i].to,v);
    }
    subtree_size[v]=c;
    return c;
}

//查找重心的递归函数，t是整个连通分量的大小
//在以v为根的子树中寻找一个顶点，使得删除该顶点后最大子树的顶点数最小
//返回值为pair(最大子树的顶点数，顶点编号)
pair<int,int> search_centroid(int v,int p,int t){
    pair<int,int> res=make_pair(INF,-1);
    //s是以v为根的子树的大小
    //m是删除v后最大子树的顶点数
    int s=1,m=0;
    for(int i=0;i<G[v].size();i++){
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;

        res=min(res,search_centroid(w,v,t));

        m=max(m,subtree_size[w]);
        s+=subtree_size[w];
    }
    m=max(m,t-s);
    res=min(res,make_pair(m,v));
    return res;
}

//计算子树中的所有顶点到重心的距离
void enumerate_paths(int v,int p,int d,vector<int> &ds){
    ds.push_back(d);
    for(int i=0;i<G[v].size();i++){
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        enumerate_paths(w,v,d+G[v][i].length,ds);
    }
}

//统计和不超过K的顶点对的个数
int count_pairs(vector<int> &ds){
    int res=0;
    sort(ds.begin(),ds.end());
    int j=ds.size();
    for(int i=0;i<ds.size();i++){
        while(j>0&&ds[i]+ds[j-1]>k) j--;
        res+=j-(j>i?1:0);//除去和本身组成的点对
    }
    return res/2;
}

//对顶点v的子树，查找重心并分割求解的递归函数
void solve_subproblem(int v){
    //查找重心s
    compute_subtree_size(v,-1);
    int s=search_centroid(v,-1,subtree_size[v]).second;
    centroid[s]=true;

    //统计按顶点s分割后子树中的对数
    for(int i=0;i<G[s].size();i++){
        if(centroid[G[s][i].to]) continue;
        solve_subproblem(G[s][i].to);
    }

    //统计经过点s的对数
    vector<int> ds;
    ds.push_back(0);
    for(int i=0;i<G[s].size();i++){
        if(centroid[G[s][i].to]) continue;

        vector<int> tds;
        enumerate_paths(G[s][i].to,s,G[s][i].length,tds);

        ans-=count_pairs(tds);
        ds.insert(ds.end(),tds.begin(),tds.end());
    }
    ans+=count_pairs(ds);
    centroid[s]=false;
}

void solve(){
    ans=0;
    solve_subproblem(0);
    printf("%d\n",ans);
}

int main(){
    while(scanf("%d%d",&n,&k)==2&&n){
        for(int i=0;i<n;i++){
            G[i].clear();
        }

        for(int i=0;i<n-1;i++){
            int a,b,l;
            scanf("%d%d%d",&a,&b,&l);
            a--;
            b--;
            G[a].push_back((edge){b,l});
            G[b].push_back((edge){a,l});
        }
        solve();
    }
    return 0;
}
