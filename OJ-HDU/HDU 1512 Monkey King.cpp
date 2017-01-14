//created by sfailsthy 2017/1/14 16:04
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn =1e5+10;

//左偏树
struct node{
    int val,dis;//键值，距离
    node *Left,*Right;//左右子树
    node * parent;//父结点
}Nodes[maxn];

int m,n,cnt;
int value[maxn];

//新结点
node *new_node(){
    node *p=Nodes+(cnt++);
    memset(p,0,sizeof(p));
    return p;
}

//清除结点信息
inline void clear(node *p){
    if(p==NULL) return;
    p->Left=p->Right=p->parent=NULL;
    p->dis=0;
    return;
}

//合并堆O(logN1+logN2)
node *merge(node *pa,node *pb){
    if(pa==NULL) return pb;
    if(pb==NULL) return pa;

    if(pb->val>pa->val) swap(pa,pb);
    pa->Right=merge(pa->Right,pb);
    if(pa->Right){
        if(pa->Left==NULL||pa->Right->dis>pa->Left->dis){
            swap(pa->Right,pa->Left);
        }
    }

    if(pa->Right==NULL) pa->dis=0;
    else pa->dis=pa->Right->dis+1;
    if(pa->Left) pa->Left->parent=pa;
    if(pa->Right) pa->Right->parent=pa;
    return pa;
}

//插入新结点O(logN)
inline node *insert(node *root,node *p){
    return merge(root,p);
}

//删除最大结点O(logN)
inline node *delete_max(node *root){
    node *p=root;
    root=merge(root->Left,root->Right);
    if(root) root->parent=NULL;
    clear(p);
    return root;
}

//取得最大值
inline int get_max(node *root){
    return root->val;
}

//构建左偏树O(N)
inline node *make_leftist_tree(){
    queue<node*> que;
    node *temp;
    temp=new_node();

    for(int i=0;i<n;i++){
        temp->val=value[i];
        que.push(temp);
    }

    while(!que.empty()){
        int len=que.size();
        if(len==1) return que.front();

        while(len--){
            node *pa=que.front();
            que.pop();
            node *pb=que.front();
            que.pop();
            que.push(merge(pa,pb));
        }
    }
}

//删除已知任意点O(logN)
inline void delete_any(node *x){
    node *q=x->parent;
    node *p=delete_max(x);
    if(p) p->parent=q;

    if(q){
        if(q->Left==x) q->Left=p;
        else q->Right=p;
    }

    while(q){
        int valLeft=-1,valRight=-1;
        if(q->Left) valLeft=q->Left->dis;
        if(q->Right) valRight=q->Right->dis;
        if(valLeft<valRight) swap(p->Left,p->Right);
        if(valRight+1==q->dis) return;
        q->dis=valRight+1;
        p=q;
        q=q->parent;
    }
}

node Ltree[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            int v;
            scanf("%d",&v);
            Ltree[i].val=v;
            Ltree[i].dis=0;
            Ltree[i].Left=Ltree[i].Right=Ltree[i].parent=NULL;
        }

        scanf("%d",&m);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;

            node *pa=Ltree+a;
            node *pb=Ltree+b;
            while(pa->parent) pa=pa->parent;
            while(pb->parent) pb=pb->parent;

            if(pa==pb) printf("-1\n");
            else{
                node *p1=delete_max(pa);
                node *p2=delete_max(pb);
                pa->val/=2;
                pb->val/=2;
                p1=insert(p1,pa);
                p2=insert(p2,pb);
                p1=merge(p1,p2);
                printf("%d\n",get_max(p1));
            }
        }
    }
    return 0;
}
