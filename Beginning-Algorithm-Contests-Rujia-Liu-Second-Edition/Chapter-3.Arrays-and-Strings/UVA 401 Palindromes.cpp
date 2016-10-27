//created by sfailsthy 2016/10/28 0:17
#include <iostream>
#include<string>
#include<cstring>
#include<ctype.h>
using namespace std;

const char rev[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[]={"is not a palindrome.","is a regular palindrome.","is a mirrored string.","is a mirrored palindrome."};

char r(char ch)
{
    if(isalpha(ch)) return rev[ch-'A'];
    return rev[ch-'0'+25];
}

int main()
{
    char s[30];
    while(cin>>s){
        int len=strlen(s);
        int p=1,m=1;
        for(int i=0;i<(len+1)/2;i++){
            if(s[i]!=s[len-1-i]) p=0;
            if(r(s[i])!=s[len-1-i]) m=0;
        }
        cout<<s<<" -- "<<msg[2*m+p]<<endl<<endl;
    }
    return 0;
}
