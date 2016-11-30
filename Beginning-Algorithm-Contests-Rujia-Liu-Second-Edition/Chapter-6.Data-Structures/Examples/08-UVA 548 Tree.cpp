//created by sfailsthy 2016/11/3 1:45
//首先根据中序序列和后序序列递归构建树，其次从根节点开始dfs搞一下，每次更新，即可确定最小的
//注意本题要求多组数据输入，而每组数据都包含多个数据，可以写一个函数单独处理(新学的技巧
#include <iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<sstream>
using namespace std;
#define INF 0x7fffffff

const int maxn=10000+10;
int inorder[maxn],postorder[maxn],lch[maxn],rch[maxn];
int n;

//读入数据
bool read(int* a)
{
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n=0;
    int x;
    while(ss>>x) a[n++]=x;
    return n>0;

}

//把inorder[L1,R1]和postorder[L2,R2]建成一棵树，返回树根
int build(int L1,int R1,int L2,int R2)
{
    if(L1>R1) return 0;
    int root=postorder[R2];
    int p=L1;
    while(inorder[p]!=root) p++;
    int cnt=p-L1;//左子树的结点个数
    lch[root]=build(L1,p-1,L2,L2+cnt-1);
    rch[root]=build(p+1,R1,L2+cnt,R2-1);
    return root;
}

int best,best_sum;

void dfs(int u,int sum)
{
    sum+=u;
    if(!lch[u]&&!rch[u]){//叶子
        if(sum<best_sum||(sum==best_sum&&u<best)){
            best=u;
            best_sum=sum;
        }
    }
    if(lch[u]) dfs(lch[u],sum);
    if(rch[u]) dfs(rch[u],sum);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(read(inorder)){
        read(postorder);
        build(0,n-1,0,n-1);
        best_sum=INF;
        int root=postorder[n-1];
        dfs(root,0);
        cout<<best<<endl;
    }
    return 0;
}
