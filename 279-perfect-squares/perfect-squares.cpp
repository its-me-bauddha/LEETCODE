class Solution {
public:
    int numSquareHelper(int n){
        // base case
        if(n == 0 ) return 1;
        if (n < 0 ) return 0;

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        while( i <= end){
          int perfectSquare = i * i ;
          int numberOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare); 
          if(numberOfPerfectSquares < ans){
             ans = numberOfPerfectSquares ;
          }
          i++;
        }
        return ans;
    }
    int numSquareHelperMem(int n ,vector<int>&dp){
        // base case
        if(n == 0 ) return 1;
        if (n < 0 ) return 0;

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);
        if(dp[n] != -1) return dp[n];
        while( i <= end){
          int perfectSquare = i * i ;
          int numberOfPerfectSquares = 1 + numSquareHelperMem(n - perfectSquare,dp); 
          if(numberOfPerfectSquares < ans){
             ans = numberOfPerfectSquares ;
          }
          i++;
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        // return numSquareHelper(n) - 1;
        vector<int> dp(n+1,-1);
        int ans = numSquareHelperMem(n,dp);
        return ans-1;
    }
};