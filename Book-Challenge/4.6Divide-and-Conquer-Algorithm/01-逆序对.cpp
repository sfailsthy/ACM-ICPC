//created by sfailsthy 2016/12/1 22:41
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long LL;

LL merge_count(vector<int> &a){
    LL cnt=0;
    int n=a.size();
    if(n<=1) return 0;
    vector<int> b(a.begin(),a.begin()+n/2);
    vector<int> c(a.begin()+n/2,a.end());

    cnt+=merge_count(b);
    cnt+=merge_count(c);

    int ai=0,bi=0,ci=0;
    while(ai<n){
        if(bi<b.size()&&(ci==c.size()||b[bi]<=c[ci])){
            a[ai++]=b[bi++];
        }
        else{
            cnt+=n/2-bi;
            a[ai++]=c[ci++];
        }
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> A;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        A.push_back(x);
    }
    printf("%lld\n",merge_count(A));
    return 0;
}
