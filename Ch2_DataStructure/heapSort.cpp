/*
堆:idx从1开始的完全二叉树，根节点为x，左儿子2x，右儿子2x+1；本题为小根堆
*/
#include <bits/stdc++.h>
using namespace std;


const int N = 100010;
int h[N], cnt;

void down(int x){
    int u = x;
    if(2 * x <= cnt && h[2*x] < h[u]) u = 2*x;
    if(2*x+1 <= cnt && h[2*x+1] < h[u]) u = 2*x+1;
    if(u != x) {
        swap(h[u], h[x]);
        down(u);            //注意down的参数为下标而非数组元素
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    cnt = n;
    for(int i = n/2; i >0; i--){
        down(i);
    }
    while(m --){
        printf("%d ",h[1]);
        h[1] = h[cnt --];
        down(1);
    }
    return 0;
}
