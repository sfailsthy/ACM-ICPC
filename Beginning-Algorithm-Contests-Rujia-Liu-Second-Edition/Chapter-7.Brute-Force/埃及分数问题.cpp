//created by sfailsthy 2016/11/6 23:41
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn =1e6+10;

ll ans[maxn];
ll v[maxn];
int maxd;

int a,b;

//get_first(a,b)是满足1/c<=a/b的最小的c
ll get_first(ll a,ll b){
	if(b%a==0) return b/a;
	else return b/a+1;
}

ll gcd(ll a,ll b)
{
	return (b==0)?a:gcd(b,a%b);
}

//判断当前解是否比ans更好
bool better(int d){
	for(int i=d;i>=0;i--){
		if(v[i]!=ans[i]){
			return ans[i]==-1||v[i]<ans[i];
		}
	}

	return false;
}

//当前深度是d，分母不能小于from，分数之和恰好是aa/bb
bool dfs(int d,int from,ll aa,ll bb){

	if(d==maxd){
		if(bb%aa) return false;//aa/bb必须是埃及分数
		v[d]=bb/aa;
		if(better(d)){
			memcpy(ans,v,sizeof(ll)*(d+1));
		}
		return true;
	}

	bool ok=false;

	from=max((ll)from,get_first(aa,bb));//枚举的起点

	for(int i=from;;i++){
		//剪枝:如果剩下的maxd+1-d个分数全部都是1/i,加起来仍然不超过aa/bb，则无解
		if(bb*(maxd+1-d)<=i*aa) break;

		v[d]=i;
		//计算aa/bb-1/i,设结果是a2/b2;
		ll a2=aa*i-bb;
		ll b2=bb*i;
		ll g=gcd(a2,b2);

		if(dfs(d+1,i+1,a2/g,b2/g)){
			ok=true;
		}
	}

	return ok;
}

void solve(){
	int ok=0;
	for(maxd=1;;maxd++){
		memset(ans,-1,sizeof(ans));

		if(dfs(0,get_first(a,b),a,b)){
			ok=1;
			break;
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int kase=0;
	while(cin>>a>>b){
		solve();

		int cnt=0;
		for(cnt=0;ans[cnt]!=-1;cnt++);

		cout<<"Case "<<++kase<<": "<<a<<"/"<<b<<"=";
		for(int i=0;i<cnt-1;i++){
			cout<<1<<"/"<<ans[i]<<"+";
		}
		cout<<1<<"/"<<ans[cnt-1]<<endl;
	}

	return 0;
}
