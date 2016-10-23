#include<iostream>  
#include<cstdio>  
using namespace std;  
int a[10][10];  
char s[10][10];  
//下标都是从0到8  
//判断(x,y)处能否放置k  
bool flag;  
bool ok(int k,int x,int y)  
{  
    for(int i=0;i<9;i++){  
        if(a[i][y]==k) return false;  
    }  
    for(int j=0;j<9;j++){  
        if(a[x][j]==k) return false;  
    }  
    int u=x-x%3,v=y-y%3;  
    for(int i=u;i<u+3;i++){  
        for(int j=v;j<v+3;j++){  
            if(a[i][j]==k) return false;  
        }  
    }  
    return true;  
}  
//从当前点(x,y)开始深度优先搜索  
void dfs(int x,int y)  
{  
    //flag是成功的标志，而放置数字是按行从上到下开始，因此x==9也是成功的标志  
    if(flag||x==9){  
        flag=true;  
        return;  
    }  
    //(x,y)处已放置数字，放置下一个格子  
    while(a[x][y]){  
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
    //枚举九个数字  
    for(int k=1;k<=9;k++){  
        if(ok(k,x,y)){  
           a[x][y]=k;  
           if(y==8) dfs(x+1,0);  
           else dfs(x,y+1);  
           if(flag) return;  
           a[x][y]=0;  
        }  
    }  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--){  
        for(int i=0;i<9;i++){  
            scanf("%s",s[i]);  
            for(int j=0;j<9;j++){  
                a[i][j]=s[i][j]-'0';  
            }  
        }  
        flag=false;  
        dfs(0,0);  
        for(int i=0;i<9;i++){  
            for(int j=0;j<9;j++){  
                printf("%d",a[i][j]);  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}  
