//created by sfailsthy 2016/12/5 14:26
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef vector<int> vec;
typedef vector<vec> mat;

int N,M;
LL k;

//计算A*B
mat mul(mat &A,mat &B){
    mat C(A.size(),vec(B[0].size()));

    for(int i=0;i<A.size();i++){
        for(int k=0;k<B.size();k++){
            for(int j=0;j<B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}

//计算A^n
mat pow(mat A,LL n){
    mat B(A.size(),vec(A[0].size()));
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

void solve(){
    mat A(N,vec(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }

    mat B(2*N,vec(2*N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i][j]=A[i][j];
        }
        B[N+i][i]=B[N+i][N+i]=1;
    }

    B=pow(B,k+1);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a=B[N+i][j]%M;
            if(i==j) a=(a+M-1)%M;
            printf("%d%c",a,j+1==N?'\n':' ');
        }
    }
}

int main(){
    scanf("%d%lld%d",&N,&k,&M);
    solve();
    return 0;
}
