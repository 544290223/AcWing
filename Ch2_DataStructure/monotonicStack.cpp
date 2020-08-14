/*
单调栈（栈是根据加入的元素动态调整的）
常见模型：找出每个数左边离它最近的比它大/小的数
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int e[N], idx;

int main(){
    int n;
    cin >> n;
    
    while(n --){
        int x;
        cin >> x;
        while(idx != 0 && x <= e[idx - 1]) idx --;
        if(idx == 0)
            cout << "-1" << " ";
        else
            cout << e[idx - 1] << " ";
        e[idx++] = x;
        }
    return 0;
}