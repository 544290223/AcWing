/*
连通块中的数量：并查集
*/
#include <iostream>
using namespace std;


const int N = 100010;
int p[N], s[N];

int find(int a){  //核心 找到根节点+路径压缩
    if(a != p[a]) p[a] = find(p[a]);  // if不是while，while会死循环
    return p[a];
}

void merge(int a, int b){
    if(find(a) == find(b)) return;   //注意，merge涉及size变化，只有祖宗节点不同才能merge
    s[find(b)] += s[find(a)];        //注意要把子节点的size加给父节点，加反出错
    p[find(a)] = find(b);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        s[i] = 1;
    }
    while(m --){
        int a, b;
        char op[3];
        scanf("%s", op);
        if(op[0] == 'C'){
            scanf("%d%d", &a, &b);
            merge(a,b);
        }
        else if(op[1] == '1'){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)){
                puts("Yes");
            }
            else{
                puts("No");
            }
        }
        else {
            scanf("%d", &a);
            cout <<  s[find(a)] <<endl;
        }
    }
    return 0;
}
