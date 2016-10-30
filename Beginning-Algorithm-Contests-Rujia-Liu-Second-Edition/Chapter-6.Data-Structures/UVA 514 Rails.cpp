//created by sfailsthy 2016/10/30 23:27
#include <iostream>
#include<stack>
#include<cstdio>
using namespace std;
const int maxn =1000+10;
int target[maxn];
int main()
{
    int n,kase=0;
    while(cin>>n&&n){
       //if(kase++) cout<<endl;
       while(cin>>target[1]&&target[1]){
            for(int i=2;i<=n;i++){
                cin>>target[i];
            }
            stack<int> s;
            bool flag=true;
            int A=1,B=1;
            while(B<=n){
                if(A==target[B]){
                    A++;
                    B++;
                }
                else if(!s.empty()&&s.top()==target[B]){
                    s.pop();
                    B++;
                }
                else if(A<=n){
                    s.push(A++);
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
       }
       cout<<endl;
    }
    return 0;
}
