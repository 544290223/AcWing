/*
trie树，存储二进制树后快速查找最大异或对。
*/
#include <iostream>
using namespace std;

const int N = 100010, M = 3000000; // 3bw怎么定
int a[N], son[M][2], idx, maxVal;

void insert(int x){
    int p = 0;
    for(int i = 30; ~i; i--){
        int b = x >> i & 1;
        if(!son[p][b]) son[p][b] = ++idx;
        p = son[p][b];
    }
    
}

int query(int x){
    int res = 0, p = 0;
    for(int i = 30; i >= 0; i--){
        int b = x >> i & 1;
        if(son[p][!b]){
            res += 1 << i;
            p = son[p][!b];
        } 
        else p = son[p][b];
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        insert(a[i]);
    }
    for(int i = 0; i < n; i++){

        maxVal = __max(maxVal,query(a[i]));
    }
    cout << maxVal;
   
    return 0;
}
