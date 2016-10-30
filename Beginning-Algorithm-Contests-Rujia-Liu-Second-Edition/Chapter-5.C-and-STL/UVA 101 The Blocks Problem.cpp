//created by sfailsthy 2016/10/31 2:15
#include <iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;

const int maxn=30;
vector<int> pile[maxn];
int n;

//找木块a所在的pile和height
void find_block(int a,int& p,int& h)
{
    for(p=0;p<n;p++){
        for(h=0;h<pile[p].size();h++){
            if(pile[p][h]==a) return;
        }
    }
}

//把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p,int h)
{
    for(int i=h+1;i<pile[p].size();i++){
        int b=pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}

//把第p堆高度为h及其上方的木块整体移到p2堆的顶部
void pile_onto(int p,int h,int p2)
{
    for(int i=h;i<pile[p].size();i++){
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

int main()
{
    int a,b;
    string s1,s2;
    cin>>n;
    for(int i=0;i<n;i++) pile[i].push_back(i);
    while(cin>>s1){
        if(s1=="quit") break;
        cin>>a>>s2>>b;
        int pa,ha,pb,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb) continue;
        if(s2=="onto") clear_above(pb,hb);
        if(s1=="move") clear_above(pa,ha);
        pile_onto(pa,ha,pb);
    }
    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int j=0;j<pile[i].size();j++) cout<<" "<<pile[i][j];
        cout<<endl;
    }
    return 0;
}
