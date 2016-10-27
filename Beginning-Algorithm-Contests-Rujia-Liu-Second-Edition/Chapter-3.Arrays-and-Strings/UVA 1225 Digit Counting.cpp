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
