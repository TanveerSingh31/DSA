
// link -> https://leetcode.com/problems/house-robber

// DP solution

class Solution {
public:

    int helper(vector<int> &nums, int index, int *dp){

        // base case
        if(index >= nums.size()) return 0;
        if(index == nums.size()-1) return nums[index];

        if(dp[index] != -1) return dp[index];

        // take 1st home, and pass index=3 to recursion and get the max amt.
        int ans1 = nums[index] + helper(nums, index+2, dp);

        int ans2 = nums[index+1] + helper(nums, index+3, dp);

        return dp[index] = max(ans1, ans2);
    }


    int rob(vector<int>& nums) {
        int *dp = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            dp[i] = -1;
        }

        return helper(nums, 0, dp);
    }
};