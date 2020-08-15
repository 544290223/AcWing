/*
堆:idx从1开始的完全二叉树，根节点为x，左儿子2x，右儿子2x+1；本题为小根堆
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N], size;

// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);          //三个顺序随意
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

// O(n)建堆
for (int i = n / 2; i; i -- ) down(i);
*/
#include <bits/stdc++.h>
using namespace std;


const int N = 100010;
int h[N], cnt, ph[N], hp[N];

void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int k){
    int u = k;
    if(2 * k <= cnt && h[2*k] < h[u]) u = 2*k;
    if(2*k+1 <= cnt && h[2*k+1] < h[u]) u = 2*k+1;
    if(u != k) {
        heap_swap(u, k);
        down(u);            //注意down的参数为下标而非数组元素
    }
}

void up(int k){
    int u = k;
    if(u/2 && h[k/2] > h[u]) u = k/2;
    if(u != k) {
        heap_swap(u, k);
        up(u);          
    }
}


int main()
{   
    int n, m = 0;
    cin >> n;
    while(n --){
        char op[5];
        int k, x;
        scanf("%s", op);
        if(!strcmp(op, "I")){
            scanf("%d", &x);
            cnt ++ ;
            m ++ ;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }else if(!strcmp(op, "PM")){
            printf("%d\n",h[1]);
        }else if(!strcmp(op, "DM")){
            //h[1] = h[cnt --];
            heap_swap(1, cnt);
            cnt --;
            down(1);
        }else if(!strcmp(op, "D")){
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt --;
            up(k);
            down(k);
        }else{
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k);
            up(k);
        }
    }
    return 0;
}
