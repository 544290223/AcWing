/*
spfa（存在负权边）

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

void spfa()
{
    
}

int main(){
    cin >> n >> m >> k;
   
    for(int i = 0; i < m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i] = {x, y, z};
        
    }
    spfa();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}