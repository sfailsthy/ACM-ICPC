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
#include<bitset>  
using namespace std;  
double EPS=1e-10;  
int main()  
{  
    int t;  
    cin>>t;  
    while(t--){  
        int ball[10];  
        for(int i=0;i<10;i++){  
            cin>>ball[i];  
        }  
        bitset<10> direction;  
        int all=1024;  
        while(all-->0){  
            direction=static_cast<bitset<10> >(all);  
            bool prefect=true;  
            int left=0;  
            int right=0;  
            for(int i=0;i<10;i++){  
                if(direction[i]){  
                    if(ball[i]>left){  
                        left=ball[i];  
                    }  
                    else{  
                        prefect=false;  
                        break;  
                    }  
                }  
                else{  
                    if(ball[i]>right){  
                        right=ball[i];  
                    }  
                    else{  
                        prefect=false;  
                        break;  
                    }  
                }  
            }  
            if(prefect){  
                break;  
            }  
        }  
        if(all>=0){  
            cout<<"YES"<<endl;  
        }  
        else{  
            cout<<"NO"<<endl;  
        }  
    }  
    return 0;  
}  
