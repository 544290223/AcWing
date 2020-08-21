/*
Dijkstra堆优化（边权为正）
稀疏图，邻接表存储图。初始距离memset为无穷大，方便使用min
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;  //距离和下标

int m,n;
const int N = 1000010;
int h[N], w[N], e[N], ne[N], idx;
int  dist[N];  //图和当前距离
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++; 
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while(heap.size()){
        PII t = heap.top();
        heap.pop();
        
        int ver = t.second;
        
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
        int t = dijkstra();
        cout << t << endl;
    return 0;
}