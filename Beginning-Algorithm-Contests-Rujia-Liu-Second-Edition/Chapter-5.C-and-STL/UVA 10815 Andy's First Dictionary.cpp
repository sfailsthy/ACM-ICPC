//created by sfailsthy 2016/11/1 15:36
#include <iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // LOCAL
    string s,buf;
    set<string> dict;
    while(cin>>s){
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        }
        stringstream ss(s);
        while(ss>>buf) dict.insert(buf);
    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
