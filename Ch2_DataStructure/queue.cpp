/*
用数组模队列，简单
// hh 表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

// 向队尾插入一个数
q[ ++ tt] = x;

// 从队头弹出一个数
hh ++ ;

// 队头的值
q[hh];

// 判断队列是否为空
if (hh <= tt)
{

}
*/
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int e[N], hh, tt;

void push(int x) {
    e[tt ++] = x;
}

void pop() {
    hh ++;
}

void empty() {
    if(tt == hh)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void query() {
    cout << e[hh] << endl;
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