/*
非负数整数的大数减法
减法要注意输出时第一个非零数前的0要去掉，例如，000000001输出成1
// C = A - B, 满足A >= B, A >= 0, B >= 0
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b){
    if(a.length() < b.length()) return false;
    else if(a.length() > b.length()) return true;
        else{
            if(a >= b) return true;
            else return false;
        }
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++){
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0 ) C.pop_back();
    return C;
}

 int main(){
    bool neg = false;
    string a, b;
    cin >> a >> b;
    if(cmp(a,b));
    else{
        string tmp = b;
        b = a;
        a = tmp;
        neg = true;
    }
    vector<int> A  , B;
    for(int i =  a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for(int i =  b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');


    auto C = sub(A, B);
    if(neg){
        cout<< "-";
        for(int i =  C.size() - 1; i >= 0; i --) cout << C[i];
    }
    else for(int i =  C.size() - 1; i >= 0; i --) cout << C[i];

    return 0;
}