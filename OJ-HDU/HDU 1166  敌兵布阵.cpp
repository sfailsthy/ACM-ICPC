//created by sfailsthy 2016/12/18 11:45
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn =50000+10;

//下标[1,n]
int bit[maxn],n;

int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}

int main(){
    //freopen("out.txt","w",stdout);
    int t,kase=0;
    scanf("%d",&t);
    while(t--){
        printf("Case %d:\n",++kase);
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            add(i,x);
        }

        for(;;){
            char str[5];
            scanf("%s",str);
            if(str[0]=='E'){
                break;
            }
            int i,j;
            scanf("%d%d",&i,&j);
            if(str[0]=='A'){
                add(i,j);
            }

            else if(str[0]=='S'){
                add(i,-j);
            }

            else{
                printf("%d\n",sum(j)-sum(i-1));
            }
        }
    }
    return 0;
}
