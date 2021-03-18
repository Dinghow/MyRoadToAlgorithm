class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash_nums;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(hash_nums.count(target-nums[i]) > 0){
                ans.push_back(hash_nums[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            hash_nums[nums[i]] = i;
        }
        return ans;
    }
};