//created by sfailsthy 2016/10/29 13:39
#include <iostream>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=150;
int main()
{
    int t;
    cin>>t;
    getc(stdin);
    while(t--){
        char str[maxn];
        gets(str);
        //cin>>str;
        int n=strlen(str);
        stack<char> s;
        for(int i=0;i<n;i++){
            if(str[i]=='['||str[i]=='('){
                s.push(str[i]);
            }
            else if(str[i]==')'){
                if(s.empty()||s.top()!='('){
                    s.push('a');
                    break;
                }
                s.pop();
            }
            else if(str[i]==']'){
                if(s.empty()||s.top()!='['){
                    s.push('a');
                    break;
                }
                s.pop();
            }
        }

        if(s.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
