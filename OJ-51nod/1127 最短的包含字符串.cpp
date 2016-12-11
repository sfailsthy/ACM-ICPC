//created by sfailsthy 2016/12/12 1:16
#include <iostream>
#include <set>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn =100000+10;
char str[maxn];

void solve(){
    set<char> all;
    for(int i=0;str[i]!='\0';i++){
        all.insert(str[i]);
    }
    if(all.size()<26){
        printf("No Solution\n");
        return;
    }

    int n=strlen(str);
    int s=0,t=0,res=n+1,num=0;
    map<char,int> cnt;
    for(;;){
        while(t<n&&num<26){
            if(cnt[str[t++]]++==0){
                num++;
            }
        }

        if(num<26){
            break;
        }

        res=min(res,t-s);
        if(--cnt[str[s++]]==0){
            num--;
        }
    }
    printf("%d\n",res);
}

int main(){
    scanf("%s",str);
    solve();
    return 0;
}
