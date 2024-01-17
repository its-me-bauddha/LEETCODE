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
    int solveTab(vector<int>&coins,int amount){
        // Step 1. create dp array & initailize 
        //dp[i] -> minimum number of coins to create i amount,
        // that's why  we initialize dp with INT_MAX
           vector<int> dp(amount+1,INT_MAX);

        // Step 2. observe base case from above
           dp[0] = 0;


        // Step 3. check the range and flow of top down appraoch & code accordingly
        for(int i = 1 ;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if((i-coins[j] >= 0) && dp[i- coins[j]] != INT_MAX ){
                    // replace/ change recursive calls of memoization by dp
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i],1 + ans);
                }
            }
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // 1 . SOLVE USING RECURSION
        // int ans = solveUsingRecursion(coins,amount);
        
        // if(ans == INT_MAX) return -1;
        //  else 
        //  return ans; 

        // // 2. TOP DOWN APPROACH (Memoization)

        // //Step 1 : create a dp array
        // vector<int> dp(amount+1,-1);
        // int ans = solveMem(coins,amount,dp);
        // if(ans == INT_MAX) return -1;
        // else 
        //     return ans;

        // 3. BOTTOM UP APPROACH (Tabulation)
        int ans = solveTab(coins,amount);
        if(ans == INT_MAX) return -1;
        else 
            return ans;

    }
};