//created by sfailsthy 2016/10/28 10:12
#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    bool ok=true;
    char c;
    while((c=getchar())!=EOF){
        if(c=='"'){
            printf("%s",ok?"``":"''");
            ok=!ok;
        }
        else printf("%c",c);
    }
    return 0;
}
