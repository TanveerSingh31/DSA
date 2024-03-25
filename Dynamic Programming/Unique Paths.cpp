// memoization ==============================================

class Solution {
public:

    int helper(int m, int n, vector<vector<int>> &dp){
        // base case
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 && n == 1) return 1;

        // check if ans exists in dp array
        if(dp[m][n] != -1) return dp[m][n];

        // recursion
        int smallAns1 = helper(m, n-1, dp);
        int smallAns2 = helper(m-1, n, dp);

        return dp[m][n] = smallAns1 + smallAns2;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
        return helper(m, n, dp);
    }
};