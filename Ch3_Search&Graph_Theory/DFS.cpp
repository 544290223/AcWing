/*
基本DFS
*/
#include <iostream>
using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs(int u){               //u表示第该层循环确定第u个数的值
    if(u == n){
        for(int i = 0; i < n; i++){
            printf("%d ", path[i]);
        }
        puts("");
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            path[u] = i;      //是u不是i
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
    }
}


int main(){
    cin >> n;
    dfs(0);
    return 0;
}