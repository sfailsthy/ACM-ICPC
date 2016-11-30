//created by sfailsthy 2016/11/30 13:13
#include <iostream>
#include <cstdio>
#include <utility>
#include <map>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const int maxn =36;
int n;
LL a[maxn];

LL abs(LL x){
    return x>0?x:(-x);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        pair<LL,int> res;//最优解,(和的绝对值，元素个数)
        map<LL,int> dp;//和→元素个数
        res=make_pair(abs(a[0]),1);

        int n2=n/2;
        //枚举前半部分
        for(int i=0;i<(1<<n2);i++){
            LL sum=0;
            int num=0;
            for(int j=0;j<n2;j++){
                if((i>>j)&1){
                    sum+=a[j];
                    num++;
                }
            }

            if(num==0){
                continue;
            }
            //更新最优解
            res=min(res,make_pair(abs(sum),num));
            map<LL,int>::iterator it=dp.find(sum);
            if(it!=dp.end()){
                it->second=min(it->second,num);
            }
            else{
                dp[sum]=num;
            }
        }

        //枚举后半部分
        for(int i=0;i<(1<<(n-n2));i++){
            LL sum=0;
            int num=0;
            for(int j=0;j<n-n2;j++){
                if((i>>j)&1){
                    sum+=a[n2+j];
                    num++;
                }
            }

            if(num==0){
                continue;
            }
            //更新最优解
            res=min(res,make_pair(abs(sum),num));
            map<LL,int>::iterator it=dp.lower_bound(-sum);//返回key大于等于-sum的指针
            //搜索-sum最相近的结果
            if(it!=dp.end()){
                res=min(res,make_pair(abs(sum+it->first),num+it->second));
            }

            if(it!=dp.begin()){
                it--;
                res=min(res,make_pair(abs(sum+it->first),num+it->second));
            }
        }

        printf("%lld %d\n",res.first,res.second);
    }
    return 0;
}
