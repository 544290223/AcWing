/*
Bellman_ford（存在负权边）
可以用结构体存储边，只要保证每次迭代都能遍历所有边即可
迭代k次，每次遍历所有边，更新距离
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
int m,n,k;
int  dist[N];  //图和当前距离
int last[N];   //上一次迭代状态的备份

struct Edge{
    int x, y, z;
}edges[M];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k; i++){
        memcpy(last, dist, sizeof dist);
        for(int j = 0; j < m; j++){   //遍历顺序无所谓
            auto e = edges[j];
            dist[e.y] = min(dist[e.y], last[e.x] + e.z);
        }
    }
}

int main(){
    cin >> n >> m >> k;
   
    for(int i = 0; i < m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i] = {x, y, z};
        
    }
    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}