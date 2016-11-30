//created by sfailsthy 2016/11/3 2:17
/*
本题的输入采取了递归方式定义，因此编写一个递归过程进行输入比较自然。
事实上，在输入过程中就能判断。由于使用引值，代码非常精简
*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<map>
using namespace std;
#define INF 0x7fffffff

//输入一个子天平，返回子天平是否平衡，参数W修改为子天平的总重量
bool solve(int& W)
{
    int W1,D1,W2,D2;
    bool flag1=true,flag2=true;
    cin>>W1>>D1>>W2>>D2;
    if(!W1) flag1=solve(W1);
    if(!W2) flag2=solve(W2);
    W=W1+W2;
    return flag1&&flag2&&(W1*D1==W2*D2);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,W;
    cin>>t;
    while(t--){
        if(solve(W)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
