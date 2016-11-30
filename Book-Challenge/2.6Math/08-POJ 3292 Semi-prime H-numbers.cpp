//created by sfailsthy 2016/11/24 23:31
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int mark[1000000+10];
int dp[1000000+10];

void init(){
    memset(mark,0,sizeof(mark));
    for(int i=5;i<=1000000+10;i+=4){
        for(int j=5;j<=i&&i*j<=1000000+10;j+=4){
            if(!mark[i]&&!mark[j]){
                mark[i*j]=1;
            }
            else{
                mark[i*j]=-1;
            }
        }
    }

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=1000000+10;i++){
        dp[i]=dp[i-1];
        if(mark[i]==1){
            dp[i]++;
        }
    }
}

int main(){
    int h;
    init();
    while(cin>>h&&h){
        cout<<h<<" "<<dp[h]<<endl;
    }
    return 0;
}
