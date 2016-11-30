//created by sfailsthy 2016/11/3 11:50
//边读入边统计
#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn =100;
int sum[maxn];

//输入并统计一棵子树，树根水平位置为p
void build(int p)
{
    int v;
    cin>>v;
    if(v==-1) return;
    sum[p]+=v;
    build(p-1);
    build(p+1);
}

//边读入边统计
bool init()
{
    int v;
    cin>>v;
    if(v==-1) return false;
    memset(sum,0,sizeof(sum));
    int pos=maxn/2;
    sum[pos]=v;
    build(pos-1);
    build(pos+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kase=0;
    while(init()){
        int p=0;
        while(sum[p]==0) p++;//找出最左边的叶子
        cout<<"Case "<<++kase<<":"<<endl<<sum[p++];
        while(sum[p]!=0) cout<<" "<<sum[p++];
        cout<<endl<<endl;
    }
    return 0;
}
