/*
差分
注意：二维操作都要处理4个点
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 1010; //取1000则溢出
int Q[N][N], s[N][N];

int main(){
    int n, m, q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) scanf("%d",&s[i][j]) ;
    }
    //求Q
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) Q[i][j] = s[i+1][j+1] - s[i][j+1] - s[i+1][j] + s[i][j];
        }
   //操作
    while(q --){
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        Q[x1-1][y1-1] += c;
        Q[x1-1][y2] -= c;
        Q[x2][y1-1] -= c;
        Q[x2][y2] += c;
    }
    //求新s，并输出
    for(int i = 1; i <= n; i++) { 
        for(int j = 1; j <= m; j++){
            s[i][j] = s[i-1][j] + s[i][j-1] -s[i-1][j-1] + Q[i-1][j-1];
            printf("%d ",s[i][j]);
        } 
        puts("");
    }
     return 0;
}