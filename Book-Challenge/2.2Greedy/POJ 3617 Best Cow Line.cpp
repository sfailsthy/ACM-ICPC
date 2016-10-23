#include<algorithm>  
#include<cctype>  
#include<cmath>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iomanip>  
#include<iostream>  
#include<map>  
#include<queue>  
#include<string>  
#include<set>  
#include<vector>  
#include<cmath>  
#include<bitset>  
#include<stack>  
#include<sstream>  
#include<deque>  
#include<utility>  
using namespace std;  
const int maxn=2005;  
  
int n;  
char s[maxn];  
  
void solve()  
{  
    int a=0,b=n-1;  
    int sum=0;  
    while(a<=b){  
        //将从左起和右起的字符串进行比较  
        bool left=false;  
        for(int i=0;a+i<=b;i++){  
            if(s[a+i]<s[b-i]){  
                left=true;  
                break;  
            }  
            else if(s[a+i]>s[b-i]){  
                left=false;  
                break;  
            }  
        }  
        sum++;  
        if(left) cout<<s[a++];  
        else cout<<s[b--];  
        if(sum%80==0){  
            cout<<endl;  
        }  
    }  
}  
int main()  
{  
    while(scanf("%d",&n)!=EOF){  
        for(int i=0;i<n;i++){  
            cin>>s[i];  
        }  
        solve();  
    }  
    return 0;  
}  
