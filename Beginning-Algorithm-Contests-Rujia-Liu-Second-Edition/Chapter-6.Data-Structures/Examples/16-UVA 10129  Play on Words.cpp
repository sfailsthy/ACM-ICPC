//created by sfailsthy 2016/12/18 14:45
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
int indegree[26];
int outdegree[26];

int par[26];
int ran[26];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        ran[i]=0;
    }
}

int find(int x){
    if(par[x]==x){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;

    if(ran[x]<ran[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(ran[x]==ran[y]){
            ran[x]++;
        }
    }
}

bool same(int x,int y){
    return find(x)==find(y);
}

bool check(){
    for(int i=0;i<26;i++){
        if(!(indegree[i]||outdegree[i])) continue;
        for(int j=0;j<26&&j!=i;j++){
            if(!(indegree[j]||outdegree[j])) continue;
            if(!same(i,j)) return false;
        }
    }

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
        init(26);

        for(int i=0;i<n;i++){
            cin>>str[i];
            int u=str[i][0]-'a';
            int v=str[i][str[i].size()-1]-'a';
            indegree[v]++;
            outdegree[u]++;
            unite(u,v);
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
