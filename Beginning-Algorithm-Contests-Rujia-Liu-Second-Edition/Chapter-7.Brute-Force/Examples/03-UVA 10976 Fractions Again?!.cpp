//created by sfailsthy 2016/10/25 22:16
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int k;
    while(scanf("%d",&k)!=EOF&&k){
        int sum=0;
        for(int y=k+1;y<=2*k;y++){
           if((k*y)%(y-k)==0){
            int x=(k*y)/(y-k);
            if(x>=y) sum++;
           }
        }
        cout<<sum<<endl;
        for(int y=k+1;y<=2*k;y++){
           if((k*y)%(y-k)==0){
            int x=(k*y)/(y-k);
            if(x>=y) printf("1/%d = 1/%d + 1/%d\n",k,x,y);
           }
        }
    }
    return 0;
}
