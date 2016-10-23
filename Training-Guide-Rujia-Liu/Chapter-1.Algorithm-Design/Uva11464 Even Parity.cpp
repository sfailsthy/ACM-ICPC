//题目链接:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2459
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
using namespace std;  
#define INF 0x7fffffff  
#define maxn 20  
int dx[]={1,-1,0,0};  
int dy[]={0,0,1,-1};  
  
int n;  
int A[maxn][maxn];  
int op[maxn][maxn];  
  
//得到元素(x,y)上下左右的元素之和(模2)  
int get(int x,int y)  
{  
    int s=0;  
    for(int i=0;i<4;i++){  
        int x2=x+dx[i];  
        int y2=y+dy[i];  
        if(0<=x2&&x2<n&&0<=y2&&y2<n){  
            if(A[x2][y2]==1){  
                s++;  
            }  
            else{  
                s+=op[x2][y2];  
            }  
        }  
    }  
    return s%2;  
}  
  
//在第一行确定的情况下，计算最小操作数  
//-1表示无解  
int calc()  
{  
    for(int i=1;i<n;i++){  
        for(int j=0;j<n;j++){  
            if(get(i-1,j)==1){  
                //1无法改变，因此(i-1,j)邻居的元素之和无法改变，是奇数，无解。  
                if(A[i][j]==1){  
                    return -1;  
                }  
                else{  
                    op[i][j]=1;  
                }  
            }  
        }  
    }  
      
    //最后一行邻居的元素之和有奇数，则无解  
    for(int j=0;j<n;j++){  
        if(get(n-1,j)==1){  
            return -1;  
        }  
    }  
      
    //统计操作数  
    int res=0;  
    for(int i=0;i<n;i++){  
        for(int j=0;j<n;j++){  
            res+=op[i][j];  
        }  
    }  
    return res;  
}  
  
void solve()  
{  
    int res=-1;  
    //枚举第一行  
    for(int i=0;i<(1<<n);i++){  
        memset(op,0,sizeof(op));  
        for(int j=0;j<n;j++){  
            //只有0才可以改变  
            if(A[0][n-1-j]==0) op[0][n-1-j]=(i>>j)&1;  
        }  
        int num=calc();  
        if(num>=0&&(res<0||res>num)){  
            res=num;  
        }  
    }  
    if(res<0){  
        res=-1;  
    }  
    printf("%d\n",res);  
}  
int main()  
{  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        for(int i=0;i<n;i++){  
            for(int j=0;j<n;j++){  
                scanf("%d",&A[i][j]);  
            }  
        }  
        printf("Case %d: ",++kase);  
        solve();  
    }  
    return 0;  
} 
