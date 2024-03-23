class Solution {
public:

    int helper(vector<int>& nums, int index, bool firstHouseRobbed, vector<pair<int, int>> &dp){
        if(index == nums.size()-1){
            if(firstHouseRobbed) return 0;
            else return nums[index]; 
        }

        if(index >= nums.size()) return 0;

        if(firstHouseRobbed && dp[index].first != -1) return dp[index].first;
        if(!firstHouseRobbed && dp[index].second != -1) return dp[index].second;

        if(index == 0) firstHouseRobbed = true;
        int take = nums[index] + helper(nums, index+2, firstHouseRobbed, dp);

        if(index == 0) firstHouseRobbed = false;
        int notTake = helper(nums, index+1, firstHouseRobbed, dp);

        if(firstHouseRobbed && index != 0) return dp[index].first = max(take, notTake);
        else if(!firstHouseRobbed && index != 0) return dp[index].second = max(take, notTake);

        return max(take, notTake);
    }


    int rob(vector<int>& nums) {
        vector< pair<int, int>> dp(nums.size(), make_pair(-1,-1));
        return helper(nums, 0, false, dp);
    }
};