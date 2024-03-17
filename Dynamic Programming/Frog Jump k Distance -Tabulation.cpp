#include<climits>


// link : https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// =============================== Tabulation =========================================

// T = O(n) , S = O(n) -> dp array

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    int * dp = new int[n];

    // add base case to dp
    dp[n-1] = 0;

    for(int i=n-2;i>=0;i--){
        int min = INT_MAX;
        for(int j=1;j<=k;j++){
            if((i+j) <= (n-1)){
                int currValue = dp[i+j] + abs(height[i+j] - height[i]);
                if(currValue < min) min = currValue;
            }
            else break;
        }
        dp[i] = min;
    }
    return dp[0];
}