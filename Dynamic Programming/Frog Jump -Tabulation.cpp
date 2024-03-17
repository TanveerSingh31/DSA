#include <bits/stdc++.h> 
#include<climits>

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // NOTE : we are taking 0 based indexing , therefore if N=4 , we will consider it as 3
    int *dp  = new int[n];

    // add base case , to dp array
    // since, we if we are standing at n-th step, we dont need to consumer any energy
    dp[n-1] = 0;

    // adding values to dp array
    for(int i=n-2;i>=0;i--){
        
        int left = dp[i+1] + abs(heights[i+1] - heights[i]);
        int right = INT_MAX;
        if(i+1 <= n){
            right = dp[i+2] + abs(heights[i+2] - heights[i]);
        }
        
        int ans = min(left, right);
        dp[i] = ans;
    }

    return dp[0];
}


// ============================ with space optimization =============================

int frogJump(int n, vector<int> &heights)
{
    // prev is pointing to index+1
    // prev2 is pointing to index+2
    int prev = 0; 
    int prev2 = INT_MAX;

    for(int i=n-2;i>=0;i--){
        int left = prev + abs(heights[i+1]-heights[i]);
        int right = INT_MAX;
        if( i+2 <= n-1){
            right = prev2 + abs(heights[i+2] - heights[i]);
        }

        int curr = min(left, right);

        // for next iteration
        prev2 = prev;
        prev = curr;
    }

    return prev;
}