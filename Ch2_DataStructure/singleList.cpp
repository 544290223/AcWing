/*
// -1代表null，head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert(int a)
{
    e[idx] = a, ne[idx] = head, head = idx ++ ;
}

// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}
*/
#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void addToHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}

void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}

void remove(int k) {
    ne[k] = ne[ne[k]];
}
int main(){
    int n;
    cin >> n;
    init();  
    while(n --){
        char s;
        int k, x;
        //scanf("%s", s);
        cin >> s;
        if (s == 'H') {
            cin >> x;
            addToHead(x);
        } else if (s == 'D') {
            cin >> k;
            if (!k) head = ne[head];
            else remove(k - 1);          
        } else if (s == 'I') {
            cin >> k >> x;
            add(k - 1, x); 
        }
    }
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}