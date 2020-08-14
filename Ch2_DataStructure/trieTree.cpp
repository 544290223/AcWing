/*
trie树，用于快速存储字符串。
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
*/
#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
    int n;
    cin >> n;
    while (n--){
        char ch, str[N];
        cin >> ch >> str;
        if (ch == 'I'){ 
            insert(str);
        } else{
            cout << query(str) << endl; 
        }
    }
    return 0;
}

