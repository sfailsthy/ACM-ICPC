//created by sfailsthy 2016/12/18 14:33
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int maxn =100000+10;

string str[maxn];
int n;
vector<int> G[26];
int indegree[26];
int outdegree[26];
int mark[26];

void dfs(int u){
    mark[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!mark[v]){
            dfs(v);
        }
    }
}

bool check(){
    int cnt=0;
    memset(mark,0,sizeof(mark));
    for(int i=0;i<26;i++){
        if(indegree[i]||outdegree[i]){
            if(!mark[i]){
                dfs(i);
                cnt++;
            }
        }
    }
    if(cnt>1) return false;

    int cnt1=0,cnt2=0;
    for(int i=0;i<26;i++){
        if(indegree[i]-outdegree[i]==1){
            cnt1++;
            if(cnt1>1) return false;
        }

        else if(outdegree[i]-indegree[i]==1){
            cnt2++;
            if(cnt2>1) return false;
        }

        else if(abs(outdegree[i]-indegree[i])>1){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(indegree,0,sizeof(indegree));
        memset(outdegree,0,sizeof(outdegree));
        for(int i=0;i<26;i++){
            G[i].clear();
        }
        for(int i=0;i<n;i++){
            cin>>str[i];
            int u=str[i][0]-'a';
            int v=str[i][str[i].size()-1]-'a';
            indegree[v]++;
            outdegree[u]++;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        bool flag=check();
        if(flag){
            printf("Ordering is possible.\n");
        }
        else{
            printf("The door cannot be opened.\n");
        }
    }
    return 0;
}
