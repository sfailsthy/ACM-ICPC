//created by sfailsthy 2016/11/3 11:08
/////两个版本，一个直接构造出后序序列，一个构造出树(每个结点的左子树和右子树)再后序遍历
///////版本一
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

/////版本二
#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn =30;
char preorder[maxn],inorder[maxn];
int n;

struct node
{
    char val;
    node *lch,*rch;
    node(){
        lch=rch=NULL;
    }
};

//preorder[L1,R1]-----inorder[L2,R2]
node* build(int L1,int R1,int L2,int R2)
{
    if(L1>R1) return NULL;
    node* root=new node;
    root->val=preorder[L1];
    char c=preorder[L1];
    int p=L2;
    while(inorder[p]!=c) p++;
    root->rch=build(L1-L2+p+1,R1,p+1,R2);
    root->lch=build(L1+1,L1-L2+p,L2,p-1);
    return root;
}
void postorder(node *p)
{
    if(p==NULL) return;
    postorder(p->lch);
    postorder(p->rch);
    cout<<p->val;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>preorder>>inorder){
        n=strlen(preorder);
        node* root=build(0,n-1,0,n-1);
        postorder(root);
        cout<<endl;
    }
    return 0;
}
