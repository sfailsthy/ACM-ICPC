//created by sfailsthy 2016/10/29 14:40
/*
每个结点都会落在根节点上，因此前两个球必然一个在根的左子树，一个在根的右子树，因此知道球编号的奇偶性就知道它第一步是往左还是往右了。
同理，对于第一步往左走的球来说，只要知道它是第几个往左走的，就可以知道下一步是往左还是往右走了。
当编号I是奇数时，它是往左走的第(I+1)/2个球；当I是偶数时，它是往右走的第I/2个球，这样可以直接模拟最后一个球的路线。
*/
#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int D,I;
    int t;
    cin>>t;
    while(t--){
        cin>>D>>I;
        int k=1;
        for(int i=0;i<D-1;i++){
            if(I%2){
                k=2*k;
                I=(I+1)/2;
            }
            else{
                k=2*k+1;
                I/=2;
            }
        }
        cout<<k<<endl;
    }
    cin>>t;
    return 0;
}
