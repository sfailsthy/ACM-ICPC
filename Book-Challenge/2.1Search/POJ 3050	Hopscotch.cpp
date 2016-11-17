//created by sfailsthy 2016/11/17 19:00

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int field[5][5];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
set<int> s;

void dfs(int x,int y,int step,int number){
    if(step==5){
        s.insert(number);
    }
    else{
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<5&&ny>=0&&ny<5)
                dfs(nx,ny,step+1,10*number+field[nx][ny]);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>field[i][j];
        }
    }

    s.clear();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(i,j,0,field[i][j]);
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
