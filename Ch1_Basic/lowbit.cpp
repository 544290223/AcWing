/*
位运算：二进制数中1的个数
scanf() yyds
求n的第k位数字: n >> k & 1
返回n的最后一位1：lowbit(n) = n & -n
*/
#include <iostream>
using namespace std;

int cnt(int x){
    int res = 0;
    while(x){
        res += x&1;
        x = x >> 1;
    }
    return res;
}
/*  lowbit
int lowbit(int x){
    return x&(-x);
}

int cnt(int x){
    int res = 0;
    while(x){
        x-=lowbit(x);
        res++;
    }
    return res;
}
*/
int main(){

    int n;
    scanf("%d", &n);
    // for(int i = 0; i < n; i++){
    //     int x;
    //     while(cin)
    // }
    
    for(int i =0; i < n; i++){
        int x, res;
        scanf("%d", &x);
        printf("%d ", cnt(x));
    }
   
    return 0;
}