//created by sfailsthy 2016/11/17 18:55

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int C(int n,int k){
	int res=1;
	for(int i=1;i<=min(k,n-k);i++){
		res=res*(n-i+1)/i;
	}
	return res;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,sum;
	cin>>n>>sum;
	int a[15];
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}

	do{
		int res=0;
		for(int i=0;i<n;i++){
			res+=C(n-1,i)*a[i];
		}

		if(res==sum){
			break;
		}
	}while(next_permutation(a,a+n));

	for(int i=0;i<n;i++){
		if(i) cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
