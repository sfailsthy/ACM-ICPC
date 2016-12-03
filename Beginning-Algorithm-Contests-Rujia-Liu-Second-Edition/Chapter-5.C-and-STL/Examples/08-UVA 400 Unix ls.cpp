//created by sfailsthy 2016/12/3 21:44
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;
const int maxn =100+10;
string filename[maxn];
int n;

void print(const string& s,int len,char extra){
    cout<<s;
    for(int i=0;i<len-s.size();i++){
        cout<<extra;
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>n){
        int M=0;
        for(int i=0;i<n;i++){
            cin>>filename[i];
            M=max(M,(int)filename[i].size());
        }
        sort(filename,filename+n);
        int cols=(60-M)/(M+2)+1;
        int rows=n/cols+((n%cols==0)?0:1);
        print("",60,'-');
        cout<<endl;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                int index=c*rows+r;
                if(index<n){
                    print(filename[index],c==cols-1?M:M+2,' ');
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
