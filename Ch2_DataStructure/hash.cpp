/*
(1) 拉链法
    int h[N], e[N], ne[N], idx;

    // 向哈希表中插入一个数
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }

    // 在哈希表中查询某个数是否存在
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;

        return false;
    }

(2) 开放寻址法
    int h[N];

    // 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x)
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x){
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

bool query(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    memset(h, -1, sizeof h); // <cstring>
    while(n --){
        string op;
        int x;
        cin >> op >> x;
        if(op == "I"){
            insert(x);
        }else{
            if(query(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}