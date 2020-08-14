/*
并查集：将两个集合合并；查询两个元素是否在同一个集合中
(1)朴素并查集：

    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);


(2)维护size的并查集：

    int p[N], size[N];
    //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    // 合并a和b所在的两个集合：
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);


(3)维护到祖宗节点距离的并查集：

    int p[N], d[N];
    //p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x)
        {
            int u = find(p[x]);
            d[x] += d[p[x]];
            p[x] = u;
        }
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        d[i] = 0;
    }

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);
    d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量
*/
#include <iostream>
using namespace std;


const int N = 100010;
int p[N];

int find(int a){  //核心 找到根节点+路径压缩
    if(a != p[a]) p[a] = find(p[a]);  // if不是while，while会死循环
    return p[a];
}

void merge(int a, int b){
    p[find(a)] = find(b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        p[i] = i;
    }
    while(m --){
        int a, b;
        char op[2];
        scanf("%s%d%d", op, &a, &b);
        if(op[0] == 'M'){
            merge(a,b);
        }else{
            if(find(a) == find(b)){
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }
    return 0;
}
