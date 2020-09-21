#include<algorithm>
bool cmp(int x, int y){
    return x > y;
}

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};