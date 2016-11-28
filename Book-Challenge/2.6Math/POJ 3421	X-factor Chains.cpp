////created by sfailsthy 2016/11/24 21:36
/*记x=p1^a1*p2^a2*p3^a3……pn^an
则最大长度是(a1+a2+……an)，数目是(a1+a2+……an)!/(a1!*a2!……an!)
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long LL;

//求解整数分解的因子的幂
vector<int> prime_factor_count(int n){
    vector<int> res;
    for(int i=2;i*i<=n;i++){
        int cnt=0;
        while(n%i==0){
            cnt++;
            n/=i;
        }
        res.push_back(cnt);
    }

    if(n!=1){
        res.push_back(1);
    }

    return res;
}

LL factor(int n){
    LL res=1;
    for(int i=1;i<=n;i++){
        res*=i;
    }
    return res;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x;
    while(cin>>x){
        vector<int> vec=prime_factor_count(x);
        int length=accumulate(vec.begin(),vec.end(),0);
        LL number=factor(length);
        for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
           number/=factor(*it);
        }
        cout<<length<<" "<<number<<endl;
    }
    return 0;
}
