//题目链接:https://code.google.com/codejam/contest/32016/dashboard#s=p2
#include<iostream>  
#include<cstdio>  
#include<vector>  
#include<cstring>  
#include<algorithm>  
#include<utility>  
#include<queue>  
using namespace std;  
  
typedef vector<int> vec;  
typedef vector<vec> mat;  
typedef long long ll;  
const int M=10000;  
//计算A*B  
mat mul(mat& A,mat& B)  
{  
    mat C(A.size(),vec(B[0].size()));  
    for(int i=0;i<A.size();i++){  
        for(int k=0;k<C.size();k++){  
            for(int j=0;j<B.size();j++){  
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;  
            }  
        }  
    }  
    return C;  
}  
//计算A^n  
mat pow(mat A,ll n)  
{  
    mat B(A.size(),vec(A.size()));  
    for(int i=0;i<A.size();i++){  
        B[i][i]=1;  
    }  
    while(n>0){  
        if(n&1) B=mul(B,A);  
        A=mul(A,A);  
        n>>=1;  
    }  
    return B;  
}  
  
const int Mod=1000;  
  
int n;  
void solve()  
{  
    mat A(2,vec(2,0));  
    A[0][0]=3;A[0][1]=5;  
    A[1][0]=1;A[1][1]=3;  
    A=pow(A,n);  
    printf("%03d\n",(A[0][0]*2+Mod-1)%Mod);  
}  
int main()  
{  
    //注意GCJ需要提交输出文件，正式比赛还需要提交源代码  
    freopen("C-large-practice.in","r",stdin);  
    freopen("C-large-practice.out","w",stdout);  
    int t,kase=0;  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        printf("Case #%d: ",++kase);  
        solve();  
    }  
    return 0;  
}  
