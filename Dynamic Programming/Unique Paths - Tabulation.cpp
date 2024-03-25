// tabulation ========================================================
// T = O(m * n)  
// S = O(m * n) dp array space

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
        
        // add base case to dp array
        for(int i=n;i>0;i--){
            dp[m][i] = 1;
        }

        //iterate from bottom to top
        for(int i=m-1;i>0;i--){
            for(int j=n;j>0;j--){
                // since, we are at last element we will skip the right operation ,it is illegal
                int ans = 0;
                if(j != n) ans += dp[i][j+1];
                ans += dp[i+1][j];

                dp[i][j] = ans;  
            }
        }


        return dp[1][1];
    }



// Space Complexity ==================================================
// T = O(m * n)
// S = O(n) , storing only the last row in array


int uniquePaths(int m, int n) {
        vector<int> lastRow(n+1, -1);

        // add base case to lastRow array
        for(int i=n;i>0;i--){
            lastRow[i] = 1;
        }

        //iterate from bottom to top
        for(int i=m-1;i>0;i--){
            vector<int> currRow(n+1, -1);
            for(int j=n;j>0;j--){
                // since, we are at last element we will skip the right operation ,it is illegal
                int ans = 0;
                if(j != n) ans += currRow[j+1];
                ans += lastRow[j];

                currRow[j] = ans;  
            }
            // copy elements from currRow to lastRow
            for(int k=n;k>0;k--){
                lastRow[k] = currRow[k];
            }
        }
        return lastRow[1];
    }