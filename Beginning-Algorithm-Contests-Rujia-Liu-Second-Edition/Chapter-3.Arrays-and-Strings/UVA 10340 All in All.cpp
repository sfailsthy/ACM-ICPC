//created by sfailsthy 2016/10/28 1:00
#include <iostream>
#include<string>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
char val[maxn];
char str[maxn];

int main()
{
    while(cin>>val>>str){
        int n1=strlen(val);
        int n2=strlen(str);
        if(n1>n2){
            cout<<"No"<<endl;
            continue;
        }
        int s=0;
        for(int i=0;i<n2;i++){
            if(s<n1&&val[s]==str[i]) s++;

        }
        if(s==n1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
