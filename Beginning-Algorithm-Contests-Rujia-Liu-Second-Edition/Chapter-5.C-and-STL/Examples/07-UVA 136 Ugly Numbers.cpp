//created by sfailsthy 2016/10/29 1:42
#include <iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

int main()
{
    int d[]={2,3,5};
    priority_queue<ll,vector<ll>,greater<ll> > que;
    set<ll> s;
    s.insert(1);
    que.push(1);
    for(int i=1;;i++){
        ll x=que.top();
        que.pop();
        if(i==1500){
            cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        for(int k=0;k<3;k++){
            ll x2=x*d[k];
            if(!s.count(x2)){
                que.push(x2);
                s.insert(x2);
            }
        }
    }
    return 0;
}
