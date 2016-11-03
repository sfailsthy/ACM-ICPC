//created by sfailsthy 2016/11/3 11:08
#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn =30;
char preorder[maxn],inorder[maxn],postorder[maxn];
int n,cnt;
//preorder[L1,R1]-----inorder[L2,R2]
void build(int L1,int R1,int L2,int R2)
{
    if(L1>R1) return;
    postorder[--cnt]=preorder[L1];
    char c=preorder[L1];
    int p=L2;
    while(inorder[p]!=c) p++;
    build(L1-L2+p+1,R1,p+1,R2);
    build(L1+1,L1-L2+p,L2,p-1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>preorder>>inorder){
        n=strlen(preorder);
        cnt=n;
        build(0,n-1,0,n-1);
        for(int i=0;i<n;i++) cout<<postorder[i];
        cout<<endl;
    }
    return 0;
}
