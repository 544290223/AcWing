/*
字符串匹配的哈希做法（替代kmp）
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int ha[N], p[N], hab, P = 131, lena, lenb;

int main(){
    string a, b;
    cin >> lenb; cin >> b; b = " " + b;
    cin >> lena; cin >> a; a = " " + a;
    p[0] = 1;
    for(int i = 1; i <= lenb; i++){     
        p[i] = p[i - 1] * P;
    }
    for(int i = 1; i <= lenb; i++) hab = hab * P + b[i] - 'a';
    for(int i = 1; i <= lena; i++) ha[i] = ha[i-1] * P + a[i] - 'a';
    for(int i = 1; i <= lena - lenb + 1; i++){
        if(ha[i+lenb-1] - ha[i-1]*p[lenb] == hab)
            cout<< i - 1 << " ";
    }
    return 0;
}