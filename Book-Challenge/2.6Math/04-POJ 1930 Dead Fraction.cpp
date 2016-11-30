//created by sfailsthy 2016/11/25
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;
typedef unsigned long long ULL;

ULL gcd(ULL a,ULL b){
    return (b==0)?a:gcd(b,a%b);
}

ULL pow(int x){
    ULL res=1;
    for(int i=0;i<x;i++){
        res*=10;
    }
    return res;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string line;
    while(cin>>line){
        if(line=="0"){
            break;
        }

        string str=line.substr(2,line.size()-5);
        unsigned int length=str.size();
        ULL n=atoi(str.c_str());
        if(n==0){
            cout<<"0/1"<<endl;
            continue;
        }

        ULL min_x=numeric_limits<ULL>::max();
        ULL min_y=0;

        for(int i=1;i<=length;i++){
            string first=str.substr(0,length-i);
            ULL x=pow(length)-pow(length-i);
            ULL y=n-atoi(first.c_str());
            ULL d=gcd(x,y);
            x/=d;
            y/=d;
            if(min_x>x){
                min_x=x;
                min_y=y;
            }
        }
        cout<<min_y<<"/"<<min_x<<endl;
    }
    return 0;
}
