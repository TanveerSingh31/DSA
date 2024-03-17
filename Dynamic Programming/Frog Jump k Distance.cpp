#include<bits/stdc++.h>

int helper(int n, int k, vector<int> &height, int index, int *dp ){
    // base case
    if(index == n-1){
        return 0;
    }

    // check if ans exists in dp arr
    if(dp[index]!=-1) return dp[index];

    // recursive calls, increasing the jump size by 1 each time
    int min = INT_MAX;
    for(int i=1;i<=k;i++){
        if(index+i <= n-1){
            // check if ans exists in dp
            int smallAns;
            if(dp[index+i] != -1) smallAns = dp[index+i];
            else{
                smallAns = helper(n, k, height, index+i,dp);
                dp[index+i] = smallAns;
            }
            int ownEffort = abs(height[index+i] - height[index]);
            if(min > (smallAns + ownEffort)) min = smallAns + ownEffort; 
        }   
        else break;
    }

    return dp[index] = min;
}


int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    int *dp = new int[n];
    for(int i=0;i<n;i++){
        dp[i] = -1;
    }
    return helper(n, k, height, 0, dp);
}