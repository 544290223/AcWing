/*
非负数整数的大数除法
注意去除多余的0
// A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}
*/
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int rem;

vector<int> div(vector<int> &A, int b){
    vector<int> C;
    int t0 = 0, res = 0;
    for(int i = A.size() - 1; i >= 0; i--){
        res = (10*t0 + A[i]) / b;
        C.push_back(res);
        t0 = (10*t0 + A[i]) % b;
    }
    rem = t0;
    
    return C;
}

 int main(){
    string a;
    int b;
    cin >> a >> b;
    if(b == 0) return 0;
    vector<int> A ;
    for(int i =  a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    vector<int> C = div(A, b);
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    for(int i =  C.size() - 1; i >= 0; i --) cout << C[i];
    cout << endl << rem;
    system("pause");
    return 0;
}

