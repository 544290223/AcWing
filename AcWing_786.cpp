/*
给定一个长度为n的整数数列，以及一个整数k，请用快速选择算法求出数列的第k小的数是多少。

输入格式
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在1~109范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第k小数。

数据范围
1≤n≤100000,
1≤k≤n
输入样例：
5 3
2 4 1 5 3
输出样例：
3
*/
#include <iostream>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

//786.第k个数
// 快速选择，只递归一边（时间复杂度o(n)）
void quick_sort(int q[], int l, int r, int k)
{
    if (l == r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if(sl < k)quick_sort(q, j + 1, r, k - sl);
    else quick_sort(q, l, j, k);
}


int main(){
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 0; i < n; i++)  scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1, k);
    printf("%d", q[k- 1]);

    getchar();
    return 0;
}