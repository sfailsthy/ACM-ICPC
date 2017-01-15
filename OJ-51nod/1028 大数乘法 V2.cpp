//created by sfailsthy 2017/1/15 15:09
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn =262200+10;
const double PI=acos(-1.0);

struct Complex{
    double real,image;
    Complex(){
        real=image=0.0;
    }

    Complex(double a,double b){
        real=a;
        image=b;
    }

    Complex operator + (const Complex &s) const{
        return Complex(real+s.real,image+s.image);
    }

    Complex operator - (const Complex &s) const{
        return Complex(real-s.real,image-s.image);
    }

    Complex operator * (const Complex &s) const{
        return Complex(real*s.real-image*s.image,real*s.image+image*s.real);
    }
}x1[maxn],x2[maxn],A[maxn];

int n,rev[maxn];
int c[maxn];

void init(int &len,int len1,int len2){
    int L=0,k=1,r,t;
    while(k<2*len1||k<2*len2){
        k<<=1;
        L++;
    }
    len=k;

    for(int i=0;i<len;i++){
        t=i;r=0;k=L;
        while(k--){
            r<<=1;
            r|=t&1;
            t>>=1;
        }
        rev[i]=r;
    }
}

//op=1,求DFT
//op=-1，求IDFT
void FFT(Complex x[],int len,int op){
    Complex u,t;
    for(int i=0;i<len;i++){
        A[rev[i]]=x[i];
    }
    for(int i=0;i<len;i++){
        x[i]=A[i];
    }

    for(int k=2;k<=len;k<<=1){
        Complex wn(cos(2*PI/k*op),sin(2*PI/k*op));
        for(int i=0;i<len;i+=k){
            Complex w(1,0);
            for(int j=0;j<k/2;j++){
                u=x[i+j];
                t=w*x[i+j+k/2];
                x[i+j]=u+t;
                x[i+j+k/2]=u-t;
                w=w*wn;
            }
        }
    }

    //IDFT
    if(op==-1){
        for(int i=0;i<len;i++){
            x[i].real/=len;
        }
    }
}

int main(){
    char str1[maxn],str2[maxn];
    while(~scanf("%s%s",str1,str2)){
        int len,len1=strlen(str1),len2=strlen(str2);
        init(len,len1,len2);
        for(int i=0;i<len;i++){
            x1[i]=Complex();
            x2[i]=Complex();
        }

        for(int i=0;i<len1;i++){
            x1[i].real=str1[len1-1-i]-'0';
        }
        for(int i=0;i<len2;i++){
            x2[i].real=str2[len2-1-i]-'0';
        }

        FFT(x1,len,1);
        FFT(x2,len,1);
        for(int i=0;i<len;i++){
            x1[i]=x1[i]*x2[i];
        }
        FFT(x1,len,-1);
        memset(c,0,sizeof(c));

        for(int i=0;i<len;i++){
            c[i]=(int)(x1[i].real+0.5);
        }

        for(int i=0;i<len;i++){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        while(len&&c[len]==0) len--;
        for(int i=len;i>=0;i--){
            printf("%d",c[i]);
        }
        printf("\n");
    }
    return 0;
}
