class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool jump_point[50000] = {0};
        jump_point[0] = 1;
        if(nums.size() == 1){
            return true;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!jump_point[i]){
                break;
            }
            int dis = nums[i];
            while(dis > 0){
                jump_point[i + dis] = true;
                dis--;
            }
        }
        if(jump_point[nums.size()-1]){
            return true;
        }
        else{
            return false;
        }
    }
};