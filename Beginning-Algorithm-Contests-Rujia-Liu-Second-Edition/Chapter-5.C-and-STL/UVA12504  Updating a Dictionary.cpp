//created by sfailsthy 2016/11/2 0:35
/*
其实这道题不算难，第一步如何分别得到key和value，前面有一道例题，是UVA 10815	Andy's First Dictionary，利用字符串流可以分离出所有的key和value。
在计数时，忘记n1=cnt/2，结果因为这个耽误了好长时间，一直在xjb调试，后来才想出来。
最后如何判断是+、-还是*，这个利用map，查找就行了。但是却因为这个耽误了好长时间，本以为没错的代码运行时却一直RE。
于是找题解，改成迭代器的形式。后来vector改成迭代器的形式才对，先保存一发。其实用i也是可以的，ans1[i]……,但是为什么前面一直RE呢？
*/
#include <iostream>
#include<sstream>
#include<string>
#include<cctype>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;

int main()
{
    /*freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        string str1[105],num1[105],str2[105],num2[105];
        for(int i=0;i<s1.size();i++){
            if(('0'<=s1[i]&&s1[i]<='9')||isalpha(s1[i])) continue;
            s1[i]=' ';
        }
        for(int i=0;i<s2.size();i++){
            if(('0'<=s2[i]&&s2[i]<='9')||isalpha(s2[i])) continue;
            s2[i]=' ';
        }
        stringstream ss1(s1);
        string buf;
        int cnt=0;
        while(ss1>>buf){
            if(cnt%2==0) str1[cnt/2]=buf;
            else num1[cnt/2]=buf;
            cnt++;
        }
        int n1=cnt/2;
        cnt=0;
        stringstream ss2(s2);
        while(ss2>>buf){
            if(cnt%2==0) str2[cnt/2]=buf;
            else num2[cnt/2]=buf;
            cnt++;
        }
        int n2=cnt/2;
        map<string,string> m1,m2;
        set<string> set1,set2;
        for(int i=0;i<n1;i++){
            m1[str1[i]]=num1[i];
            set1.insert(str1[i]);
        }
        for(int i=0;i<n2;i++){
            m2[str2[i]]=num2[i];
            set2.insert(str2[i]);
        }
        vector<string> ans1,ans2,ans3;
        for(int i=0;i<n2;i++){
            if(set1.count(str2[i])!=0){
                if(m1[str2[i]]!=m2[str2[i]]){
                        ans3.push_back(str2[i]);
                }
            }
            else{
                ans1.push_back(str2[i]);
            }
        }
        for(int i=0;i<n1;i++){
            if(set2.count(str1[i])==0){
                ans2.push_back(str1[i]);
            }
        }

        if(ans1.empty()&&ans2.empty()&&ans3.empty()){
            cout<<"No changes"<<endl;
        }
        else{
            vector<string>::iterator it;
            if(!ans1.empty()){
                sort(ans1.begin(),ans1.end());
                cout<<"+";
                for(it=ans1.begin();it!=ans1.end()-1;it++){
                    cout<<*it<<",";
                }
                it=ans1.end()-1;
                cout<<*it<<endl;
            }

            if(!ans2.empty()){
                sort(ans2.begin(),ans2.end());
                cout<<"-";
                for(it=ans2.begin();it!=ans2.end()-1;it++){
                    cout<<*it<<",";
                }
                it=ans2.end()-1;
                cout<<*it<<endl;
            }
            if(!ans3.empty()){
                sort(ans3.begin(),ans3.end());
                cout<<"*";
                for(it=ans3.begin();it!=ans3.end()-1;it++){
                    cout<<*it<<",";
                }
                it=ans3.end()-1;
                cout<<*it<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
