/*
用数组模拟栈，简单
// tt表示栈顶
int stk[N], tt = 0;

// 向栈顶插入一个数
stk[ ++ tt] = x;

// 从栈顶弹出一个数
tt -- ;

// 栈顶的值
stk[tt];

// 判断栈是否为空
if (tt > 0)
{

}
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int e[N], idx;

void push(int x) {
    e[idx ++] = x;
}

void pop() {
    idx--;
}

void empty() {
    if(idx == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void query() {
    cout << e[idx - 1] << endl;
}


int main(){
    int n;
    cin >> n;
    

    while(n --){
        string s;
        int x;
        cin >> s;
        if (s == "push") {
            cin >> x;
            push(x);
        } else if (s == "pop") {
            pop();
        } else if (s == "empty") {
            empty();
        } else if(s == "query") {
            query();
        }
    }
    return 0;
}