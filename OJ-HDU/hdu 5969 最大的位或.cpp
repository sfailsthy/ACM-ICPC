//created by sfailsthy 2016/11/24 19:02
/*
把L，R用二进制表示，之后根据二进制表示长度大小的关系分类讨论。
具体讨论见代码。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long LL;

LL Pow(int x,int n){
    LL res=1;
    for(int i=0;i<n;i++){
        res=(LL)(res*x);
    }
    return res;
}

vector<int> binary(LL n){
    vector<int> res;
    while(n!=0){
        res.push_back(n%2);
        n=n/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

LL solve(vector<int> vec){
    int len=vec.size();
    LL res=0;
    for(int i=0;i<len;i++){
        if(vec[i]==0) continue;
        res+=Pow(2,len-1-i);
    }
    return res;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        LL L,R;
        cin>>L>>R;
        vector<int> vec1=binary(L);
        vector<int> vec2=binary(R);
        int len1=vec1.size();
        int len2=vec2.size();

        vector<int> res;
        if(len1!=len2){
            for(int i=0;i<len2;i++){
                res.push_back(1);
            }
            cout<<solve(res)<<endl;
        }

        else{
            int p=-1;
            for(int i=0;i<len1;i++){
                if(vec1[i]!=vec2[i]){
                    p=i;
                    break;
                }
            }

            if(p==-1){
                cout<<L<<endl;
            }
            else{
                for(int i=0;i<p;i++){
                    res.push_back(vec1[i]);
                }

                for(int i=p;i<len1;i++){
                    res.push_back(1);
                }
                cout<<solve(res)<<endl;
            }
        }
    }
    return 0;
}
