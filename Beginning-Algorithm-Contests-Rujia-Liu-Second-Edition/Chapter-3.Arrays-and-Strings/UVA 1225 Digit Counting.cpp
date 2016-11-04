//created by sfailsthy 2016/10/27 17:56
#include<bits/stdc++.h>
using namespace std;

vector<int> bit(int n)
{
    vector<int> a;
    while(n!=0){
        a.push_back(n%10);
        n=n/10;
    }
    return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> s;
        for(int i=0;i<=9;i++){
            s[i]=0;
        }
        for(int i=1;i<=n;i++){
            vector<int> a=bit(i);
            for(int j=0;j<a.size();j++){
                s[a[j]]++;
            }
        }
        for(int i=0;i<9;i++){
            cout<<s[i]<<" ";
        }
        cout<<s[9]<<endl;
    }
    return 0;
}

/////////////
#include <iostream>
#include<utility>
#include<queue>
#include<deque>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int sum[10];
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            int j=i;
            while(j>0){
                sum[j%10]++;
                j=j/10;
            }
        }
        for(int i=0;i<9;i++){
            cout<<sum[i]<<" ";
        }
        cout<<sum[9]<<endl;
    }
    return 0;
}
