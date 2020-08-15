/*
试除法分解质因数
N只会有一个大于sqrt（N）的质因数，所以在最后单独输出
*/
#include <iostream>
using namespace std;

void dec_prime(int x){
    if(x < 2) return ;
    for(int i = 2; i <= x/i; i++){  
        int cnt = 0;
        while(x % i == 0){
            cnt ++;
            x /= i;
        }
        if(cnt) cout << i << " " << cnt << endl; 
    }
    if(x > 1) cout << x << " " << 1 << endl;  
}

int main(){
    int n;
    cin >> n;
    while(n --){
        int x;
        cin >> x;
        dec_prime(x);
        puts(" ");
    }
    return 0;
}