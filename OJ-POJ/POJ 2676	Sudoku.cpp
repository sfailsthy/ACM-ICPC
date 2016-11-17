//created by sfailsthy 2016/11/17

#include <iostream>
#include <cstdio>
using namespace std;

char s[9][9];
int field[9][9];
bool flag;

bool check(int k,int x,int y){
    for(int i=0;i<9;i++){
        if(field[x][i]==k) return false;
        if(field[i][y]==k) return false;
    }

    int u=x-x%3;
    int v=y-y%3;

    for(int i=u;i<u+3;i++){
        for(int j=v;j<v+3;j++){
            if(field[i][j]==k) return false;
        }
    }

    return true;
}

void dfs(int x,int y){
    if(flag||x==9){
        flag=true;
        return;
    }

    while(field[x][y]){
        if(y==8){
            x++;
            y=0;
        }
        else y++;

        if(x==9){
            flag=true;
            return;
        }
    }

    for(int k=1;k<=9;k++){
        if(check(k,x,y)){
            field[x][y]=k;
            if(y==8) dfs(x+1,0);
            else dfs(x,y+1);

            if(flag) return;
            field[x][y]=0;
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<9;i++){
            cin>>s[i];
            for(int j=0;j<9;j++){
                field[i][j]=s[i][j]-'0';
            }
        }

        flag=false;
        dfs(0,0);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<field[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
