//created by ssailsthy 2016/10/31 12:33
/*
本题的集合并不是简单的整数集合或者字符串集合，而是集合的集合，为了方便起见为每个不同的集合分配一个唯一的ID，而每个集合都可以表示成所包含元素的ID集合
注意STL中内置的集合的操作*/
#include <iostream>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ALL(x) x.begin(),x.end()//所有的内容
#define INS(x) inserter(x,x.begin())//插入迭代器
map<set<int>,int> IDcache;//把集合映射成ID
vector<set<int> > Setcache;//按ID取集合

//查找集合的ID，如果找不到，分配一个新的ID
int ID(set<int> x)
{
   if(IDcache.count(x)) return IDcache[x];
   Setcache.push_back(x);//添加新集合
   return IDcache[x]=Setcache.size()-1;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        stack<int> s;
        for(int i=0;i<n;i++){
            string op;
            cin>>op;
            if(op[0]=='P') s.push(ID(set<int>()));
            else if(op[0]=='D') s.push(s.top());
            else{
                set<int> x1=Setcache[s.top()];s.pop();
                set<int> x2=Setcache[s.top()];s.pop();
                set<int> x;
                if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
                else if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
                else if(op[0]=='A'){
                    x=x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}
