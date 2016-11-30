//created by sfailsthy 2016/10/27 17:48
#include<bits/stdc++.h>
using namespace std;
const int maxn =85;
int dp[maxn];
char s[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        if(s[0]=='O') dp[0]=1;
        else dp[0]=0;
        int n=strlen(s);
        for(int i=1;i<n;i++){
            if(s[i]=='O') dp[i]=dp[i-1]+1;
            else dp[i]=0;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=dp[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
