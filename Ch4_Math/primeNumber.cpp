/*
试除法判断质数：
1.小于2的既不是质数也不是合数
2.注意边界
*/
#include <iostream>
using namespace std;

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x/i; i++){  //2.注意边界  <=
        if(x % i == 0) return false;  
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n --){
        int x;
        cin >> x;
        if(is_prime(x)) puts("Yes");
        else puts("No");
    }
    return 0;
}