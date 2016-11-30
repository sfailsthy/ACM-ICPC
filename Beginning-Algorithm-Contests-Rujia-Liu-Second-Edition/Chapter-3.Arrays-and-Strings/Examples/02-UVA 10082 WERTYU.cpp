//created by sfailsthy 2016/10/29 1:02
#include <iostream>
#include<cstdio>
using namespace std;
const char s[]="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    char c;
    while((c=getchar())!=EOF){
        int i;
        for(i=1;s[i]&&s[i]!=c;i++);
        if(s[i]) putchar(s[i-1]);
        else putchar(c);
    }
    return 0;
}
