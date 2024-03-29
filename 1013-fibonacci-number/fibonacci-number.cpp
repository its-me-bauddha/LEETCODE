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
        if(n == 1 || n == 0 )
        return n; 

        // STEP 3 :  Check ans if already exists
        if(dp[n] != -1)
        return dp[n];

        // STEP 2 : replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp) + topDownSolve(n-2,dp);
        return dp[n];
    }

    int bottomUpSolve(int n){

        // STEP 1 : create DP array
        int dp[100];

        // STEP 2 : Observe base case in above solution
        dp[0] = 0 ;
        dp[1] = 1 ;

        // STEP 3 : 
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }

    int spaceOptimizationSolve(int n){
        // STEP 1 : make two variables 
        int prev1 = 0 ;
        int prev2 = 1 ;

        if(n==0) return prev1;
        if(n==1) return prev2;

        // STEP 2: 
        int curr;
        for(int i=2;i<=n;i++){
           curr = prev1 + prev2 ;
           // shifting 
           prev1 = prev2;
           prev2 = curr;
        }

        return curr;
    }
    int fib(int n) {
        // 1. recursive solution
        // int ans = recursiveSolve(n);
        // return ans;

        // 2. top down approch (momeoization)
        // STEP 1 : Create  DP array
        // vector<int> dp(n+1,-1);
        // int ans = topDownSolve(n,dp);
        // return ans ;

        // 3. bottom up approach
        // int ans = bottomUpSolve(n);
        // return ans;


        // 4. space optimization
        return spaceOptimizationSolve(n);
    }
};