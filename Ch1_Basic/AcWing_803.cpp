/*
区间合并
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII> &segs){
    int l = -2e9, r = -2e9;
    vector<PII> res;
    sort(segs.begin(), segs.end());
    for(auto seg : segs){
        if(seg.first > r){
            if(l != -2e9) res.push_back({l, r}); 
            l = seg.first;
            r = seg.second;
         }else r = max(seg.second, r);
    }
    if(l != -2e9)  res.push_back({l, r}); 
    segs = res;
}
 
 
int main() { 
    int n;
    cin >> n;
    vector<PII> segs;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r}); 
     }

    merge(segs);

    cout<< segs.size();
     
    return  0;
}