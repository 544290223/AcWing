/*
双指针（简单）
两头夹击
*/
#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main(){
    int n, m, x;
    scanf("%d%d%d",&n,&m,&x);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d",&b[i]);
    }
    for (int i = 0, j = m - 1; i < n; i ++ )
    {
        while (j >= 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;   //去掉 j >= 0 &&  也通过了
    }
    
    return 0;
}