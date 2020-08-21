/*

*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n,m;
int g[N][N], d[N][N];

int bfs(){
    queue<PII> q;
    memset(d, -1, sizeof(d));

    d[0][0] = 0;
    q.push({0,0});
    int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

    while(q.size()){
        PII t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >=0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] != 1){
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x,y});
            }

        }

    }
    return d[n - 1][m - 1];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    cout << bfs() << endl;
    return 0;
}