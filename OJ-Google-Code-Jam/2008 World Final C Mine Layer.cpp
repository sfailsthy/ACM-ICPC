#include<iostream>  
#include<cstdio>  
#include<vector>  
#include<cstring>  
#include<algorithm>  
#include<utility>  
#include<queue>  
using namespace std;  
  
#define MAX_RC 50  
int R,C;  
int A[MAX_RC][MAX_RC];  
  
//计算长度为n的一维版问题的总和  
int total(int *a,int n)  
{  
    int res=0;  
    //按模3的余数讨论  
    if(n%3==1||n%3==2){  
        for(int i=0;i<n;i+=3){  
            res+=a[i];  
        }  
    }  
    else{  
        for(int i=1;i<n;i+=3){  
            res+=a[i];  
        }  
    }  
    return res;  
}  
  
//计算长度为n的一维版问题正中央的数字  
int center(int *a,int n)  
{  
    int res;  
    //按模3的余数讨论  
    if(n%3==1){  
        res=total(a,n);  
        for(int i=1;i<n/2;i+=3){  
            res-=a[i];  
            res-=a[n-1-i];  
        }  
    }  
    else if(n%3==2){  
        res=total(a,n);  
        for(int i=0;i<n/2;i+=3){  
            res-=a[i];  
            res-=a[n-1-i];  
        }  
    }  
    else{  
        res=0;  
        for(int i=0;i<n/2;i+=3){  
            res+=a[i];  
            res+=a[n-1-i];  
        }  
        res-=total(a,n);  
    }  
    return res;  
}  
int main()  
{  
    freopen("C-large-practice.in","r",stdin);  
    freopen("C-large-practice.out","w",stdout);  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d%d",&R,&C);  
        for(int i=0;i<R;i++){  
            for(int j=0;j<C;j++){  
                scanf("%d",&A[i][j]);  
            }  
        }  
        int row[MAX_RC];  
        for(int i=0;i<R;i++){  
            row[i]=total(A[i],C);  
        }  
        int ans=center(row,R);  
        printf("Case #%d: %d\n",++kase,ans);  
    }  
    return 0;  
}  
