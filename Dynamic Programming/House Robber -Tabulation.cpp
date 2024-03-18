// Tabulation solution ============================

class Solution {
public:


    int rob(vector<int>& nums) {
        int *dp = new int[nums.size()];
        if(nums.size()==1) return nums[0];
        // add base case to dp arr
        dp[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            int ans1 = nums[i];
            if(i+2 <= nums.size()-1) ans1 += dp[i+2];
        
            int ans2 = dp[i+1];
    
            dp[i] = max(ans1, ans2);
        }
        
        return dp[0];
    }
};

// Tabulation -> SPACE OPTIMIZATION ====================

class Solution {
public:


    int rob(vector<int>& nums) {
        
        // added base case to prev
        int prev2 = INT_MIN , prev = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            int ans1 = nums[i];
            if(i+2 <= nums.size()-1) ans1 += prev2;
        
            int ans2 = prev;

            int curr = max(ans1, ans2);    
             
            // for next iteration
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};