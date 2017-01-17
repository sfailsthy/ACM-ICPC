//created by sfailsthy 2017/1/18 1:24
/**************************************************************
    Problem: 3527
    User: sfailsthy
    Language: C++
    Result: Accepted
    Time:3764 ms
    Memory:17680 kb
****************************************************************/
 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=262200+10;
const double PI =acos(-1.0);
 
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
double a[maxn/2],b[maxn/2],c[maxn/2];
 
void init(int &len,int len1,int len2){
    int k=1,L=0,r,t;
    while(k<2*len1||k<2*len2){
        k<<=1;
        L++;
    }
 
    len=k;
    for(int i=0;i<len;i++){
        t=i,r=0,k=L;
        while(k--){
            r<<=1;
            r|=t&1;
            t>>=1;
        }
        rev[i]=r;
    }
}
 
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
 
    if(op==-1){
        for(int i=0;i<len;i++){
            x[i].real/=len;
        }
    }
}
 
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    for(int i=1;i<n;i++){
        b[i]=1.0/i/i;
    }
 
    int len,len1=n,len2=n;
    init(len,len1,len2);
    for(int i=0;i<len;i++){
        x1[i]=Complex();
        x2[i]=Complex();
    }
    for(int i=0;i<len;i++){
       x1[i]=Complex(a[i],0);
       x2[i]=Complex(b[i],0);
    }
 
    FFT(x1,len,1);
    FFT(x2,len,1);
    for(int i=0;i<len;i++){
        x1[i]=x1[i]*x2[i];
    }
    FFT(x1,len,-1);
    for(int i=0;i<n;i++){
        c[i]=x1[i].real;
    }
 
    for(int i=0;i<len;i++){
        x1[i]=Complex();
        x2[i]=Complex();
    }
    for(int i=0;i<n;i++){
        x1[i]=Complex(a[n-1-i],0);
        if(i) x2[i]=Complex(b[i],0);
    }
    FFT(x1,len,1);
    FFT(x2,len,1);
    for(int i=0;i<len;i++){
        x1[i]=x1[i]*x2[i];
    }
    FFT(x1,len,-1);
    for(int i=0;i<n;i++){
        c[i]-=x1[n-1-i].real;
    }
 
    for(int i=0;i<n;i++){
        printf("%.3lf\n",c[i]);
    }
    return 0;
}
