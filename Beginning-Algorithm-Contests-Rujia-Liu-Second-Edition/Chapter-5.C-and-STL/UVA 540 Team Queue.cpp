//created by sfailsthy 2016/10/31 13:31
//使用全局变量结果WA……，原因是多局数据全局变量在使用前应该置空，使用局部变量就不需要了
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxt=1000+10;
int main()
{
    /*freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    int t,kase=0;
    while(cin>>t&&t){
        cout<<"Scenario #"<<++kase<<endl;
        map<int,int> team;//人的编号→团队的编号
        for(int i=0;i<t;i++){
            int n;
            cin>>n;
            while(n--){
                int x;
                cin>>x;
                team[x]=i;
            }
        }

        queue<int> que1,que2[maxt];//que1是团队的队列，que2[i]是团队i成员的队列
        string op;
        while(cin>>op){
            if(op[0]=='S') break;
            else if(op[0]=='D'){
                int t=que1.front();
                cout<<que2[t].front()<<endl;
                que2[t].pop();
                if(que2[t].empty()) que1.pop();
            }
            else if(op[0]=='E'){
                int x;
                cin>>x;
                int t=team[x];
                if(que2[t].empty()) que1.push(t);
                que2[t].push(x);
            }
        }
        cout<<endl;
    }
    return 0;
}
