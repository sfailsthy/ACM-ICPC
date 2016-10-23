#include <algorithm>  
#include <cctype>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <iostream>  
#include <map>  
#include <queue>  
#include <string>  
#include <set>  
#include <vector>  
using namespace std;  
  
#define maxn 50  
  
int N;  
int M[maxn][maxn];//矩阵  
  
int a[maxn];//a[i]表示第i行最后出现1的位置  
  
void solve()  
{  
    int res=0;  
    for(int i=0;i<N;i++){  
        a[i]=-1;//如果不含1，就当作-1  
        for(int j=0;j<N;j++){  
            if(M[i][j]==1){  
                a[i]=j;  
            }  
        }  
    }  
    for(int i=0;i<N;i++){  
        int pos=-1;//要移动到第i行的行  
        for(int j=i;j<N;j++){  
            if(a[j]<=i){  
                pos=j;  
                break;  
            }  
        }  
        //完成交换  
        for(int j=pos;j>i;j--){  
            swap(a[j],a[j-1]);  
            res++;  
        }  
    }  
    printf("%d\n",res);  
}  
int main()  
{  
    freopen("A-large-practice.in","r",stdin);  
    freopen("A-large-practice.out","w",stdout);  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&N);  
        for(int i=0;i<N;i++){  
            char s[maxn];  
            cin>>s;  
            for(int j=0;j<N;j++){  
                M[i][j]=s[j]-'0';  
            }  
        }  
        printf("Case #%d: ",++kase);  
        solve();  
    }  
    return 0;  
}  
