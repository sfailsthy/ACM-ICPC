//created by sfailsthy 2016/11/20 19:59

/*
1.题目描述:煎饼朝上或者朝下，每次可以翻转一整行或者一整列，问最后朝上的煎饼的最大个数。1<=R<=10,1<=C<=10000.

2.解题思路:行数较小可以二进制枚举，之后每一列并不是真正的翻转，只要取朝上和朝下的最大值即可。
bitset内置函数flip可以使二进制数逐位取反。
时间复杂度为O(R*2^R*C)
*/

#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
const int maxn =1e4+10;
bitset<maxn> cookie[15];

int R,C;
void solve(){
    int res=0;
    for(int i=0;i<(1<<R);i++){
        //完成当前行的翻转
        for(int j=0;j<R;j++){
            if((i>>j)&1){
                cookie[j].flip();
            }
        }

        //判断每一列朝上和朝下的个数，取最大值
        //可能的最大值
        int cnt=0;
        for(int j=0;j<C;j++){
            int upcnt=0;
            for(int k=0;k<R;k++){
                upcnt+=cookie[k][j];
            }
            cnt+=max(upcnt,R-upcnt);
        }
        res=max(res,cnt);

        //复原
        for(int j=0;j<R;j++){
            if((i>>j)&1){
                cookie[j].flip();
            }
        }
    }

    cout<<res<<endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while((cin>>R>>C)&&R&&C){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                int x;
                cin>>x;
                cookie[i][j]=x;
            }
        }
        solve();
    }
    return 0;
}
