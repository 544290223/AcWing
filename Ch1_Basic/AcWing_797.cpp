/*
差分（前缀和逆操作）
注意：s和q的下标差1
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 100010; //取1000则溢出
int q[N], s[N];

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) {
         scanf("%d",&s[i]) ;
    }

    for(int i = 0; i < n; i++) { 
        q[i] = s[i+1] - s[i];
    }
    while(m --){
        int l, r, c;
        scanf("%d%d%d",&l, &r, &c);
        q[l-1] += c;
        q[r] -= c;
    }
     for(int i = 1; i <= n; i++){  
        s[i] = s[i-1] + q[i-1];
        printf("%d ",s[i]);
     }
   
    return 0;
}