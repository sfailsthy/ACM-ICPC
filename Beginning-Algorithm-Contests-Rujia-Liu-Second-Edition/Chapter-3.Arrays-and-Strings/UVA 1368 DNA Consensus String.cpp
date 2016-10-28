//created by sfailsthy 2016/10/28 10:48
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn =1010;
const int A=0,C=1,G=2,T=3;
int cnt[5][maxn];
char str[60][maxn];
char ans[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>str[i][j];
            }
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(str[i][j]=='A'){
                    cnt[A][j]++;
                }
                else if(str[i][j]=='C'){
                    cnt[C][j]++;
                }
                else if(str[i][j]=='G'){
                    cnt[G][j]++;
                }
                else if(str[i][j]=='T'){
                    cnt[T][j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<4;j++){
                if(cnt[j][i]>cnt[x][i]){
                    x=j;
                }
            }
            if(x==A) ans[i]='A';
            else if(x==C) ans[i]='C';
            else if(x==G) ans[i]='G';
            else if(x==T) ans[i]='T';
        }
        ans[n]='\0';
        cout<<ans<<endl;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[j]!=str[i][j]) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
