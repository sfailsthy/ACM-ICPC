//created by sfailsthy 2016/10/27 18:13
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int ans[maxn];

int main()
{
    memset(ans,0,sizeof(ans));
    for(int m=1;m<=maxn;m++){
        int x=m,y=m;
        while(x>0){
            y+=x%10;
            x/=10;
        }
        if(y>maxn) continue;
        if(ans[y]==0||m<ans[y]) ans[y]=m;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;

    }
    return 0;
}
