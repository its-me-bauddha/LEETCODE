class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount){
        // base case 
        if(amount == 0 ) return 0;
        if(amount < 0) return INT_MAX;

        // traverse the whole coins arr
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans =solveUsingRecursion(coins,amount-coins[i]);

            if(ans != INT_MAX){
                // ans is valid , update the mini
                // ans -> me 1 plus karna pedegaa 
                mini = min(ans+1,mini);
            }
        }

        return mini;
    }

    int solveMem(vector<int>& coins, int amount,vector<int>& dp){
        // base case 
        if(amount == 0) return 0;
        if(amount < 0 ) return INT_MAX;

        // ans alrady exists
        if(dp[amount] != -1) return dp[amount];

        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveMem(coins,amount - coins[i],dp);
            if(ans != INT_MAX){
                mini =min(1+ ans,mini); 
            }
        }
        dp[amount] = mini;
        return mini;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        // 1 . SOLVE USING RECURSION
        // int ans = solveUsingRecursion(coins,amount);
        
        // if(ans == INT_MAX) return -1;
        //  else 
        //  return ans; 

        // 2. TOP DOWN APPROACH (Memoization)

        //Step 1 : create a dp array
        vector<int> dp(amount+1,-1);
        int ans = solveMem(coins,amount,dp);
        if(ans == INT_MAX) return -1;
        else 
            return ans;
    }
};