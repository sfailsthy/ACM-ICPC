//created by sfailsthy 2016/12/2 11:16
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS=1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

//求解Ax=b,其中A是方阵
//当无解或者无穷多解时，返回长度为0的数组
vec gauss_jordan(const mat& A,const vec& b){
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            B[i][j]=A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        B[i][n]=b[i];
    }

    for(int i=0;i<n;i++){
        //把正在处理的未知系数的绝对值最大的式子换到i行
        int pivot=i;
        for(int j=i;j<n;j++){
            if(abs(B[j][i])>abs(B[pivot][i])){
                pivot=j;
            }
        }
        swap(B[i],B[pivot]);

        //无解或者无穷多解
        if(abs(B[i][i])<EPS) return vec();

        //把正在处理的未知数的系数变成1
        for(int j=i+1;j<=n;j++){
            B[i][j]/=B[i][i];
        }
        for(int j=0;j<n;j++){
            if(i!=j){
                //从第j个式子中消去第i个未知数
                for(int k=i+1;k<=n;k++){
                    B[j][k]-=B[j][i]*B[i][k];
                }
            }
        }
    }

    vec x(n);
    for(int i=0;i<n;i++){
        x[i]=B[i][n];
    }
    return x;
}

const int maxn =15;
int N,M;
char grid[maxn][maxn];

bool can_goal[maxn][maxn];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

//搜索可以到达终点的点
void dfs(int x,int y){
    can_goal[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<N&&0<=ny&&ny<M&&!can_goal[nx][ny]&&grid[nx][ny]!='#'){
            dfs(nx,ny);
        }
    }
}

void solve(){
    mat A(N*M,vec(N*M,0));
    vec b(N*M,0);
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            can_goal[x][y]=false;
        }
    }
    dfs(N-1,M-1);

    //构建矩阵
    for(int x=0;x<N;x++){
        for(int y=0;y<M;y++){
            //到达终点或者无法到达的情况
            if((x==N-1&&y==M-1)||!can_goal[x][y]){
                A[x*M+y][x*M+y]=1;
                continue;
            }

            //其余情况
            int move=0;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(0<=nx&&nx<N&&0<=ny&&ny<M&&grid[nx][ny]=='.'){
                    A[x*M+y][nx*M+ny]=-1;
                    move++;
                }
            }
            b[x*M+y]=A[x*M+y][x*M+y]=move;
        }
    }

    vec res=gauss_jordan(A,b);
    printf("%.8f\n",res[0]);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d%d",&N,&M)==2&&N){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>grid[i][j];//scanf("%s",grid[i]);
            }
        }
        solve();
    }
    return 0;
}

/*
Sample input
10 10
..######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.####
....#.....

10 10
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........

3 10
.#...#...#
.#.#.#.#.#
...#...#..

Sample output
1678.00000000
542.10052168
361.00000000
*/
