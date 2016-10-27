//created by sfailsthy 2016/10/27 23:43
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

const int maxn =105;
int judge(char *s,int p,int q)
{
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[(p+i)%n]!=s[(q+i)%n])
            return s[(p+i)%n]-s[(q+i)%n];
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        char s[maxn];
        cin>>s;
        int n=strlen(s);
        int ans=0;
        for(int i=1;i<n;i++){
            if(judge(s,i,ans)<0){
                ans=i;
            }
        }
        for(int i=0;i<n;i++){
            cout<<s[(ans+i)%n];
        }
        cout<<endl;
    }
    return 0;
}
