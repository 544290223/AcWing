/*
前缀和
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int q[N], s[N];

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i  = 0; i < n; i++) scanf("%d",&q[i]);

    for(int i  = 1; i <= n; i++) s[i] = q[i - 1] + s[i - 1];
    while(m --){
        int l, r;
        scanf("%d%d",&l,&r);
        cout<< s[r] - s[l - 1] <<endl;
    }

    return 0;
}