#include <bits/stdc++.h>
#include<cstring>
using namespace std;


int fibonacci(int n, int *dp){
    
    // base case
    if(n <=1 ){
        return n;
    }
    
    // check if the ans exist in dp array
    if(dp[n] != -1 ) return dp[n];
    
    // recursive call
    int ans = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    
    // store ans for this subproblem in dp array
    dp[n] = ans;
    
    return ans;
}


int main() {
	// your code goes here
	int *dp = new int[5+1];
    //===================================================================================
    // for dp 
	for(int i=0;i<6;i++){
	    dp[i] = -1;
	}
	cout<<fibonacci(5, dp)<<endl;

    for(int i=0;i<6;i++){
	    cout<<dp[i]<<" ";
	}
	cout<<endl;

    //===================================================================================
    // for tabulation
    // add base case , in dp array
    dp[0] = 0;
    dp[1] = 1;

    // no need to call rescursion , only iteratively add elements from down to top
    for(int i=2;i<=5;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[5]<<endl;

    // ========================================================================
    // eliminating space complexity (no need of addit. array)
    int prev = 1, prev2 = 0;
    for(int i=2;i<=5;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<< prev << endl;
	
}
