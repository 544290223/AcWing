/*
找出数组中重复的数字
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return -1; 
        for(auto i : nums){
            if(i < 0 || i > n - 1) return -1;
        }
        
        for(int i = 0; i < n; i++){
            while(i != nums[i]){
                if(nums[i] == nums[nums[i]]) return nums[i];
                else swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 1, -10, 1, 1, 4, 3, 10, 1, 1};
    s.duplicateInArray(nums);
    return 0;
}