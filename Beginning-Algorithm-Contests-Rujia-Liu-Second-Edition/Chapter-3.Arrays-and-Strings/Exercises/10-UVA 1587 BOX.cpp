//created by sfailsthy 2016/10/28 11:16
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int,int> P;
P a[6];
bool check()
{
    if(a[0]!=a[1]||a[2]!=a[3]||a[4]!=a[5]) return false;
    if(a[0].first!=a[2].first||a[0].second!=a[4].first||a[2].second!=a[4].second) return false;
    return true;
}
int main()
{
    while(cin>>a[0].first>>a[0].second>>a[1].first>>a[1].second>>a[2].first>>a[2].second>>a[3].first>>a[3].second>>a[4].first>>a[4].second>>a[5].first>>a[5].second){
        for(int i=0;i<6;i++){
            if(a[i].first>a[i].second){
                swap(a[i].first,a[i].second);
            }
        }
        sort(a,a+6);
        bool flag=check();
        if(flag) cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
