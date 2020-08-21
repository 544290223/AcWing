/*
Dijkstra（边权为正）
稠密图，使用邻接矩阵储存图。初始距离memset为无穷大，方便使用min
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int m,n;
const int N = 510;
int g[N][N], dist[N];  //图和当前距离
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ ) //n-1或n都可
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if(t == n ) break;               //前n个点的最短路确定后，dist[n]就已经确定
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);  //为了使min有作用，将g初始化为“无穷大”
    }
    
        int t = dijkstra();
        cout << t << endl;
    return 0;
}