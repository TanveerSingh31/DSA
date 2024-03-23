// Tabulation =================================================

int rob(vector<int>& nums) {
        vector< pair<int, int>> dp(nums.size(), make_pair(-1,-1));

        // tabulation method
        // add base case to dp array
        dp[nums.size()-1].first = 0;
        dp[nums.size()-1].second = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){

            // taking those cases where we are robbing first house
            int take1 = nums[i];
            if(i+2 <= nums.size()-1) take1 += dp[i+2].first;

            int dontTake1 = dp[i+1].first;

            dp[i].first = max(take1, dontTake1);

            // taking those cases where we are not robbit first house
            int take2 = nums[i];
            if(i == 0) take2 = 0; // since in this case we are not taking the first element , therefore when reaching index = 0, avoid considering first element
            if(i+2 <= nums.size()-1) take2 += dp[i+2].second;

            int dontTake2 = dp[i+1].second;

            dp[i].second = max(take2, dontTake2);
        }

        return max(dp[0].first, dp[0].second); 
}


// space optimization =================================================


