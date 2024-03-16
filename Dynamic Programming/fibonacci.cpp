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
	
	for(int i=0;i<6;i++){
	    dp[i] = -1;
	}
	cout<<fibonacci(5, dp)<<endl;
	
	for(int i=0;i<6;i++){
	    cout<<dp[i]<<" ";
	}
	cout<<endl;
}
