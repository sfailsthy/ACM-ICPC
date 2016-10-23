#include <iostream>  
#include <algorithm>  
#include <cctype>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iomanip>  
#include <map>  
#include <queue>  
#include <string>  
#include <set>  
#include <vector>  
#include<utility>  
#include<cmath>  
using namespace std;  
double EPS=1e-10;  
  
#define maxn 105  
int W,H;  
char farm[maxn][maxn];  
int dx[]={1,-1,0,0};  
int dy[]={0,0,1,-1};  
  
void dfs(int x,int y,char c)  
{  
    farm[x][y]='x';  
    for(int i=0;i<4;i++){  
        int nx=x+dx[i];  
        int ny=y+dy[i];  
        if(0<=nx&&nx<W&&0<=ny&&ny<H&&farm[nx][ny]==c){  
            dfs(nx,ny,c);  
        }  
    }  
}  
  
int main()  
{  
    while(cin>>H>>W&&W&&H){  
        /*for(int i=0;i<W;i++){ 
            for(int j=0;j<H;j++){ 
                cin>>farm[i][j]; 
            } 
        } 
        int res=0; 
        for(int x=0;x<W;x++){ 
            for(int y=0;y<H;y++){ 
                if(farm[x][y]!='x'){ 
                    dfs(x,y,farm[x][y]); 
                    res++; 
                } 
            } 
        }*/  
        for(int j=0;j<H;j++){  
            for(int i=0;i<W;i++){  
                cin>>farm[i][j];  
            }  
        }  
        int res=0;  
        for(int y=0;y<H;y++){  
            for(int x=0;x<W;x++){  
                if(farm[x][y]!='x'){  
                    dfs(x,y,farm[x][y]);  
                    res++;  
                }  
            }  
        }  
        cout<<res<<endl;  
    }  
    return 0;  
}  
