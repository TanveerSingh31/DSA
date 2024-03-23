// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003


// dynamic programming


int findMax(vector<int> &arr, int & lastSelectedIndex){
    int ans;
    int max = 0;
    for(int i=0;i<3;i++){
        if(arr[i] >= max && i != lastSelectedIndex){
            max = arr[i];
        }
    }
    return max;
}


int helper(vector<vector<int>> &points, int currIndex, vector<vector<int>> &dp, int lastSelectedIndex){
    
    // base case
    if(currIndex == points.size()-1){
        return findMax(points[currIndex], lastSelectedIndex);
    }  

    if(lastSelectedIndex >= 0 && dp[currIndex][lastSelectedIndex] != -1) return dp[currIndex][lastSelectedIndex];

    // own computation
    int currMax = 0;
    int index;
    for(int i=0;i<3;i++){
        if(i == lastSelectedIndex) continue;
        int smallAns = helper(points, currIndex+1, dp, i);
        // dp[currIndex][i] = smallAns + points[currIndex][i];
        if(smallAns + points[currIndex][i] > currMax){
            currMax = smallAns + points[currIndex][i];
        } 
    }
    if(lastSelectedIndex >= 0) dp[currIndex][lastSelectedIndex] = currMax;
    return currMax;
}


int ninjaTraining(int n, vector<vector<int>> &points){
    // Write your code here.
    int lastSelectedIndex = -1;
    vector<vector<int>> dp(points.size(), std::vector<int>(3, -1));
    int ans = helper(points, 0, dp, lastSelectedIndex);
    // print(dp);
    return ans;

}