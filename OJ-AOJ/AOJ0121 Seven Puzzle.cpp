//题目链接:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0121
#include <iostream>  
#include<string>  
#include<map>  
#include<queue>  
#include<algorithm>  
using namespace std;  
map<string,int> dp;  
int direction[]={1,-1,4,-4};  
//分别代表右移、左移、下移、上移  
void bfs()  
{  
    queue<string> que;  
    que.push("01234567");  
    dp["01234567"]=0;  
    while(!que.empty()){  
        string now=que.front();  
        que.pop();  
        //p是字符串中0的位置  
        int p=0;  
        for(int i=0;i<8;i++){  
            if(now[i]=='0'){  
                p=i;  
                break;  
            }  
        }  
        for(int i=0;i<4;i++){  
            int n=p+direction[i];  
            if(n>=0&&n<8&&!(p==3&&i==0)&&!(p==4&&i==1)){  
                //右上角不能向右移、左下角不能向左移  
                string next=now;  
                swap(next[p],next[n]);  
                if(dp.find(next)==dp.end()){  
                    //用find函数来定位数据出现位置，它返回的一个迭代器，  
                    //当数据出现时，它返回数据所在位置的迭代器，  
                    //如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器  
                    dp[next]=dp[now]+1;  
                    que.push(next);  
                }  
            }  
        }  
    }  
}  
int main()  
{  
    bfs();  
    string s;  
    while(getline(cin,s)){  
       s.erase(remove(s.begin(),s.end(),' '),s.end());  
       cout<<dp[s]<<endl;  
    }  
    return 0;  
} 
