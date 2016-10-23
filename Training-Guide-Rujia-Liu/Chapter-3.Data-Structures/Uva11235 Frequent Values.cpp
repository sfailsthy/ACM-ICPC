//题目链接:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2176
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
#define INF 0x7fffffff  
#define maxn 100005  
#define maxlog 20  
int d[maxn][maxlog];  
  
//d[i][j]表示从i开始的，长度为2^j的一段元素中的最小值  
void RMQ_init(const vector<int> &A)  
{  
    int n=A.size();  
    for(int i=0;i<n;i++){  
        d[i][0]=A[i];  
    }  
    for(int j=1;(1<<j)<=n;j++){  
        for(int i=0;i+(1<<j)-1<n;i++){  
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);  
        }  
    }  
}  
  
int RMQ(int L,int R)  
{  
    int k=0;  
    while((1<<(k+1))<=(R-L+1)) k++;  
    return max(d[L][k],d[R-(1<<k)+1][k]);  
}  
  
int n,q;  
int a[maxn];  
int num[maxn],Left[maxn],Right[maxn];  
//num[p]表示位置p所在段的编号  
//Left[p],Right[p]分别表示位置p所在段的左右端点位置  
int main()  
{  
    while(scanf("%d",&n)!=EOF&&n){  
        scanf("%d",&q);  
        for(int i=0;i<n;i++){  
            scanf("%d",&a[i]);  
        }  
        a[n]=a[n-1]+1;//哨兵  
        int start=-1;  
        vector<int> count;  
        for(int i=0;i<=n;i++){  
            if(i==0||a[i]>a[i-1]){  
                //新一段开始  
                if(i>0){  
                    count.push_back(i-start);  
                    for(int j=start;j<i;j++){  
                        num[j]=count.size()-1;  
                        Left[j]=start;  
                        Right[j]=i-1;  
                    }  
                }  
                start=i;  
            }  
        }  
  
        RMQ_init(count);  
        int ans=0;  
        for(int i=0;i<q;i++){  
            int l,r;  
            scanf("%d%d",&l,&r);  
            l--;  
            r--;  
            if(num[l]==num[r]){  
                ans=r-l+1;  
            }  
            else{  
                ans=max(Right[l]-l+1,r-Left[r]+1);  
                if(num[l]+1<num[r]){  
                    ans=max(ans,RMQ(num[l]+1,num[r]-1));  
                }  
            }  
            printf("%d\n",ans);  
        }  
    }  
    return 0;  
}  
