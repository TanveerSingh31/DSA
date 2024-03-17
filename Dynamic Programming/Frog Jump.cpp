#include <bits/stdc++.h> 
#include<climits>

int helper(int n, vector<int> &heights, int currIndex, int *dp){

    // base case
    // if we are standing on the step, we will not consume any enery
    if(currIndex+1 == n) return 0;

    // check if ans exists in dp arr.
    if(dp[currIndex] != -1) return dp[currIndex];

    // own computation
    // take 1st step and pass on to recursion
    int smallAns1 = helper(n, heights, currIndex+1, dp);
    int energyConsumed1 = smallAns1 + abs(heights[currIndex+1] - heights[currIndex]); 

    // take 2 steps and pass on to recursion
    int energyConsumed2;
    if(currIndex+2 >= heights.size()) return energyConsumed1;
    else{
        int smallAns2 = helper(n, heights, currIndex+2, dp);
        energyConsumed2 = smallAns2 + abs(heights[currIndex+2] - heights[currIndex]);
    }

    int ans = min(energyConsumed1, energyConsumed2);
    dp[currIndex] = ans;
    return ans;
}



int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int *dp  = new int[n];
    for(int i=0;i<n;i++){
        dp[i] = -1;
    }
    return helper(n, heights, 0, dp);
}