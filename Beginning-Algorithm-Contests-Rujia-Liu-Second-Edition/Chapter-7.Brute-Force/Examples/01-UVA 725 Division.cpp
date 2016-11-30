//creat by sfailsthy 2016.10.25.15:18
#include<bits/stdc++.h>
using namespace std;

inline bool check(int x,int y)
{
    char s[15];
    sprintf(s,"%05d%05d",x,y);
    for(char i='0';i<='9';i++){
        if(!strchr(s,i)) return false;
    }
    return true;
}
int main()
{
    int abcde,fghij,n,kase=0;
    while(scanf("%d",&n)!=EOF&&n){
        if(kase++) printf("\n");
        bool ok=false;
        for(fghij=1234;fghij<=98765;fghij++){
            abcde=n*fghij;
            if(abcde<100000&&check(abcde,fghij)){
                printf("%05d / %05d = %d\n",abcde,fghij,n);
                ok=true;
            }
        }
        if(!ok){
            printf("There are no solutions for %d.\n",n);
        }

    }
    return 0;
}
