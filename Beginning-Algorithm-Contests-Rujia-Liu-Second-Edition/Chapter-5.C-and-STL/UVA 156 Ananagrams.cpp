//created by sfailsthy 2016/10/31 1:24
#include <iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;

map<string,int> cnt;
vector<string> words;

//将单词s标准化
string repr(const string& s)
{
    string ans=s;
    for(int i=0;i<ans.length();i++){
        ans[i]=tolower(ans[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;
    while(cin>>s){
        if(s[0]=='#') break;
        words.push_back(s);
        string r=repr(s);
        if(!cnt.count(r)) cnt[r]=0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i=0;i<words.size();i++){
        if(cnt[repr(words[i])]==1) ans.push_back(words[i]);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
