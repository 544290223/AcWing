/*
g++条件下 #include<bits/stdc++.h>
 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> vecS;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(ss >> s){
        vecS.push_back(s);
    }
    return 0;
}