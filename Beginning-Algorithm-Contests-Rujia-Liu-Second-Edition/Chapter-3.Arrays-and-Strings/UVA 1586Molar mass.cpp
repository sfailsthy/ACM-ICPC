//created by sfailsthy 2016/10/28 22:55
#include <iostream>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
#define C 0
#define H 1
#define O 2
#define N 3
const int maxn=80+10;
char str[maxn];
int cnt[5];
void solve()
{
    int n=strlen(str);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        if(isalpha(str[i])){
            int j=i+1;
            queue<int> que;
            while(j<n&&(!isalpha(str[j]))){
                que.push(str[j]-'0');
                j++;
            }
            int res=0;
            while(!que.empty()){
                int x=que.front();
                que.pop();
                res=res*10+x;
            }
            if(j==i+1) res=1;
            switch(str[i]){
            case 'C':
                cnt[C]+=res;
                break;
            case 'H':
                cnt[H]+=res;
                break;
            case 'O':
                cnt[O]+=res;
                break;
            case 'N':
                cnt[N]+=res;
                break;
            }
        }
    }
    double ans=0;
    ans+=cnt[H]*1.008+cnt[O]*16.00+cnt[C]*12.01+cnt[N]*14.01;
    /*cout<<"C H O N"<<endl;
    cout<<cnt[C]<<" "<<cnt[H]<<" "<<cnt[O]<<" "<<cnt[N]<<endl;*/
    printf("%.3lf\n",ans);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        solve();
    }
    return 0;
}
