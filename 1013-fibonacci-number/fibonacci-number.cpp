class Solution {
public:
    int recursiveSolve(int n ){
         // base case 
        if(n == 1 || n== 0 )
        return n; 

        return recursiveSolve(n-1) +recursiveSolve(n-2);
    }
    int topDownSolve(int n ,vector<int>&dp){
        // base case 
        if(n == 1 || n== 0 )
        return n; 

        // STEP 3 :  Check ans if already exists
        if(dp[n] != -1)
        return dp[n];

        // STEP 2 : replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        // 1. recursive solution
        // int ans = recursiveSolve(n);
        // return ans;

        // 2. top down approch (momeoization)
        // STEP 1 : Create  DP array
        vector<int> dp(n+1,-1);
        int ans = topDownSolve(n,dp);
        return ans ;
    }
};