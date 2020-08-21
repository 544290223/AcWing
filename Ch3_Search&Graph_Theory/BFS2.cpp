/*
八数码
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;


int bfs(string state){
    queue<string> q;
    unordered_map<string, int> d;

    q.push(state);
    d[state] = 0;
    int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
    string end = "12345678x";
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t == end) return d[t];

        int dis = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;

        for(int i = 0; i < 4; i++){
            int a = x + dx[i], b = y + dy[i];
            if(a >=0 && a < 3 && b >= 0 && b < 3){
                swap(t[k], t[a*3 + b]);
                if(!d.count(t)){
                    d[t] = dis + 1;
                    q.push(t);
                }

                swap(t[k], t[a*3 + b]);
            }

        }

    }
    return -1;
}

int main(){
    char s[2];
    string state;
    for(int i = 0; i < 9; i++){
        scanf("%s", s);
        state += s[0];
    }

    cout << bfs(state) << endl;
    return 0;
}