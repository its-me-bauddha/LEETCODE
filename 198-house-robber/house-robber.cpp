class Solution {
public:
    
    int solveUsingRecursion(vector<int>&nums,int n){
        // n -> represents the index of current house
        // base case
        // 1. no house exists
        if(n < 0) return 0;
        // 2. only one house exists
        if(n == 0) return nums[0];


        // include index
        int include = solveUsingRecursion(nums,n-2) + nums[n];

        // exclude index
        int exclude =  solveUsingRecursion(nums,n-1) ;

        return max(include,exclude);

    }
    int solveUsingMem(vector<int>& nums,int n ,vector<int>& dp){
        // n -> represents the index of current house
        // base case
        // 1. no house exists
        if(n < 0) return 0;
        // 2. only one house exists
        if(n == 0) return nums[0];

        // step 3 check ans already exists  or not !
        if(dp[n] != -1) return dp[n];

        int include = solveUsingMem(nums,n-2,dp) + nums[n];// include index
        int exclude =  solveUsingMem(nums,n-1,dp) ; // exclude index

        // step 2 :  store the ans in dp array 
        dp[n] =  max(include,exclude);
        return dp[n];
    }
    int solveUsingTab(vector<int>&nums,int n){
        // step 1 create dp array
        vector<int> dp(n+1,0);

        // step 2 check base case and store it in dp array
        dp[0] = nums[0];

        // step 3 observe top down approach
        for(int i =1;i<=n;i++){
            int temp = 0 ; // stores the i-2th index value from the curr index
            if(i-2 >= 0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1];
            dp[i] = max(include ,exclude);
        }

        return dp[n];

    }
    int spaceOptimizedSolution(vector<int>&nums,int n){
        
        int prev2 = 0; 
        int prev1 = nums[0];
        // dp[i] -> depends on dp[i-1] and dp[i-2] so here the optimzation  is possible
        // using three varaible we can solve this problem 
        
        int curr;
        for(int i =1;i<=n;i++){
            int temp = 0 ;
            if(i-2 >= 0){
                temp = prev2;
            }
            int include = temp + nums[i];
            int exclude = prev1;
            curr = max(include ,exclude);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;

    }
    int rob(vector<int>& nums) {
          int n = nums.size()-1;

        // 1. RECURSION SOLUTION
        // return solveUsingRecursion(nums,n);

        // 2. TOP DOWN APPROACH (MEMOIZATION method)
        // step 1 create dp array 
        // vector<int> dp(n+1,-1);
        // return solveUsingMem(nums,n,dp);

        // 3 . BOTTOM UP APPROACH (Tabulation method)
        // return solveUsingTab(nums,n);

        // 4. SPACE OPTIMIZATION
        return spaceOptimizedSolution(nums,n);
       
    }
};