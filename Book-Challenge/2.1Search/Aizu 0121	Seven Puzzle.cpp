//created by sfailsthy 2016/11/17 18:47

#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

const int dx[]={1,-1,4,-4};
map<string,int> dp;

void bfs(){ 
    queue<string> que;
    que.push("01234567");
    dp["01234567"]=0;

    while(!que.empty()){
        string now=que.front();
        que.pop();
        int x=0;
        while(now[x]!='0') x++;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            if(nx>=0&&nx<8&&!(x==3&&i==0)&&!(x==4&&i==1)){
                string next=now;
                swap(next[x],next[nx]);
                //用find函数来定位数据出现位置，它返回的一个迭代器，  
                //当数据出现时，它返回数据所在位置的迭代器，  
                //如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器
                if(dp.find(next)==dp.end()){
                    dp[next]=dp[now]+1;
                    que.push(next);
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    bfs();
    string s;
    while(getline(cin,s)){
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        cout<<dp[s]<<endl;
    }
    return 0;
}
