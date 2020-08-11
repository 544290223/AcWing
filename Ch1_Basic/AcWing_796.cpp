/*
二维前缀和（子矩阵的和）
注意：边界条件：N和循环时取等号
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 1010; //取1000则溢出
int Q[N][N], s[N][N];

int main(){
    int n, m, q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) scanf("%d",&Q[i][j]) ;
    }

    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= m; j++) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + Q[i-1][j-1];
    }
 
    while(q --){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        cout<< s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1] <<endl;
    }

    return 0;
}