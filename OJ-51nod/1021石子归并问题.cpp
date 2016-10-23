//题目链接:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1021
#include <iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
#define INF 0x7fffffff  
  
const int maxn=105;  
int a[maxn];  
int sum[maxn];  
int dp[maxn][maxn];  
int n;  
  
int main()  
{  
    cin>>n;  
    sum[0]=0;  
    for(int i=1;i<=n;i++){  
        cin>>a[i];  
        sum[i]=sum[i-1]+a[i];  
    }  
    memset(dp,0,sizeof(dp));  
    for(int len=2;len<=n;len++){  
        for(int i=1;i<=n;i++){  
            int j=len+i-1;  
            dp[i][j]=INF;  
            for(int k=i;k<=j;k++){  
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);  
            }  
        }  
    }  
    cout<<dp[1][n]<<endl;  
    return 0;  
}  
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
#include <iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
#define INF 0x7fffffff  
  
const int maxn=210;  
int a[maxn];  
int sum[maxn];  
int dp[maxn][maxn];  
int s[maxn][maxn];  
int n;  
  
int main()  
{  
    cin>>n;  
    sum[0]=0;  
    for(int i=1;i<=n;i++){  
        cin>>a[i];  
        s[i][i]=i;  
        sum[i]=sum[i-1]+a[i];  
    }  
    memset(dp,0,sizeof(dp));  
    for(int len=2;len<=n;len++){  
        for(int i=1;i<=n;i++){  
            int j=len+i-1;  
            dp[i][j]=INF;  
            for(int k=s[i][j-1];k<=s[i+1][j];k++){  
                if(dp[i][j]>dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]){  
                    dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];  
                    s[i][j]=k;  
                }  
            }  
        }  
    }  
    cout<<dp[1][n]<<endl;  
    return 0;  
}  
