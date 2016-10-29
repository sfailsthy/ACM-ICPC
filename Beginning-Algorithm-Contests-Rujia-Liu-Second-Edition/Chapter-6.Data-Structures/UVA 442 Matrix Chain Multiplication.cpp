//created by sfailsthy 2016/10/29 14:01
#include <iostream>
#include<stack>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
typedef pair<int,int> Matrix;

int main()
{
    int n;
    cin>>n;
    Matrix ma[26];
    stack<Matrix> s;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        cin>>ma[c-'A'].first>>ma[c-'A'].second;
    }
    string exp;
    while(cin>>exp){
        int n=exp.size();
        int res=0;
        bool error=false;
        for(int i=0;i<n;i++){
            if(isalpha(exp[i])) s.push(ma[exp[i]-'A']);
            else if(exp[i]==')'){
                Matrix m2=s.top();s.pop();
                Matrix m1=s.top();s.pop();
                if(m1.second!=m2.first){
                    error=true;
                    break;
                }
                res+=m1.first*m1.second*m2.second;
                s.push((Matrix(m1.first,m2.second)));
            }
        }
        if(error) cout<<"error"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
