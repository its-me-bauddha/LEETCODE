class Solution {
public:
    int solveMem(int n ,vector<int>&dp){
        // base case
        if(n==0 || n==1) return 1;
        
        // already exits ans in dp array
        if(dp[n] != -1 ){
            return dp[n];
        }

        // function call and store the ans in dp array
        dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp); 


        return  dp[n];
    }
    int climbStairs(int n) {
        // int arr[50];
        //  arr[0] = 1;
        //  arr[1] = 1 ;
        // for(int i = 2 ; i <= n ;i++){
        //     arr[i] = arr[i-1] + arr[i-2];
        // }
        // return arr[n];


        // create dp array
        vector<int> dp(n+1,-1);
        int ans = solveMem(n,dp);

        return ans;
    }
};