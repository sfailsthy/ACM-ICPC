//created by sfailsthy 2016/11/17 18:49

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 0x7fffffff

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string all;
        getline(cin,all);
        all.erase(remove(all.begin(),all.end(),' '),all.end());
        int length=all.size();
        int cnt=length/2;
        int res=INF;

        for(int k=0;k<(1<<length);k++){
            string s1,s2;

            for(int i=0;i<length;i++){
                if((k>>i)&1){
                    s1+=all[i];
                }
                else{
                    s2+=all[i];
                }
            }

            if(s1.size()!=cnt) continue;

            if(s1[0]=='0'&&s1.size()>1) continue;

            do{
                int n1=atoi(s1.c_str());
                do{
                    if(s2[0]=='0'&&s2.size()>1){
                        continue;
                    }

                    int n2=atoi(s2.c_str());
                    int dif=abs(n1-n2);

                    res=min(res,dif);
                }while(next_permutation(s2.begin(),s2.end()));
            }while(next_permutation(s1.begin(),s1.end()));

        }

        cout<<res<<endl;
    }
    return 0;
}



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
#include <cmath>  
#include <bitset>  
using namespace std;  
  
int main()  
{  
    int n;  
    cin>>n;  
    cin.ignore();  
    while(n--){  
        string all;  
        getline(cin,all);  
        all.erase(remove(all.begin(),all.end(),' '),all.end());//删除空格  
        int length=all.size();  
        int cut=length/2;  
        int permute=1<<length;  
        int result=0x7fffffff;  
        do{  
            bitset<10> used=static_cast<bitset<10> >(permute);  
            string s1,s2;  
            for(int i=0;i<length;i++){  
                if(used[i]){  
                    s1+=all[i];  
                }  
                else{  
                    s2+=all[i];  
                }  
            }  
            if(s1.size()!=cut){  
                continue;  
            }  
            if(s1[0]=='0'&&s1.size()>1){  
                continue;  
            }  
            //s1,s2已经枚举出来了  
            //穷举它们  
            do{  
                int n1=atoi(s1.c_str());//将字符串转化成整数  
                do{  
                    if(s2[0]=='0'&&s2.size()>1){  
                        continue;  
                    }  
                    int n2=atoi(s2.c_str());//将字符串转化成整数  
                    int dif=abs(n1-n2);  
                    //cout<<s1<<" "<<s2<<"dif:"<<dif<<"result:"<<result<<endl;  
                    result=min(dif,result);  
                }while(next_permutation(s2.begin(),s2.end()));//全排列  
  
            }while(next_permutation(s1.begin(),s1.end()));  
  
        }while(--permute);  
  
        cout<<result<<endl;  
    }  
    return 0;  
} 










