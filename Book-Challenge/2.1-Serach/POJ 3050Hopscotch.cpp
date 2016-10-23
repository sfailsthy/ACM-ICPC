#include <algorithm>  
#include <cctype>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <iostream>  
#include <map>  
#include <queue>  
#include <string>  
#include <set>  
#include <vector>  
#include<cmath>  
using namespace std;  
  
int Map[5][5];  
int dx[]={1,-1,0,0};  
int dy[]={0,0,1,-1};  
set<int> res;  
  
void dfs(int x,int y,int step,int number)  
{  
    if(step==5){  
        res.insert(number);  
        return;  
    }  
    else{  
        for(int i=0;i<4;i++){  
            int nx=x+dx[i];  
            int ny=y+dy[i];  
            if(0<=nx&&nx<5&&0<=ny&&ny<5){  
                dfs(nx,ny,step+1,10*number+Map[nx][ny]);  
            }  
        }  
    }  
}  
  
int main()  
{  
    for(int i=0;i<5;i++){  
        for(int j=0;j<5;j++){  
            cin>>Map[i][j];  
        }  
    }  
    res.clear();  
    for(int i=0;i<5;i++){  
        for(int j=0;j<5;j++){  
            dfs(i,j,0,Map[i][j]);  
        }  
    }  
    cout<<res.size()<<endl;  
    return 0;  
}  
