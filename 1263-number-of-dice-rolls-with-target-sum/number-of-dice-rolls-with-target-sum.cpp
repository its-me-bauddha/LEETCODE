class Solution {
public:
    int MOD = 1000000007;
    int solveUsingRecursion(int n,int k,int target){
        // base case 
        if(n < 0 ) return 0;
        if(n == 0 && target == 0 ) return 1;
        if(n == 0 && target != 0 ) return 0;
        if(n != 0 && target == 0 ) return 0;
        
       
        int ans = 0 ;
        for(int i=1;i<=k;i++){
            ans += solveUsingRecursion(n-1,k,target-i);
        }
        return ans;
    }
    long long int solveUsingMem(int n,int k,int target,vector<vector<long long int>>&dp){
        // base case 
        if(n < 0 ) return 0;
        if(n == 0 && target == 0 ) return 1;
        if(n == 0 && target != 0 ) return 0;
        if(n != 0 && target == 0 ) return 0;

        if(dp[n][target] != -1){
            return dp[n][target];
        }
        long long int ans = 0 ;
        for(int i=1;i<=k;i++){
            long long int ansRec = 0 ;
           if(target- i >=0){
               ansRec = solveUsingMem(n-1,k,target-i,dp);
           } 
           ansRec  = ansRec % MOD;
           ans  = ans%MOD ;
           ans = (ans + ansRec) % MOD;
        }
        dp[n][target] = ans;
        return dp[n][target];
    }
    int solveUsingTabulation(int n ,int k ,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1 , 0 ));
        dp[0][0] = 1;

        for(int index = 1 ; index <= n ;index++){
            for(int t= 1;t<=target;t++){
                long long int ans = 0 ;
                for(int i=1;i<=k;i++){
                    long long int ansRec = 0 ;
                    if(t- i >=0)
                       ansRec = dp[index-1][t-i];
                    ansRec  = ansRec % MOD;
                    ans  = ans%MOD ;
                    ans = (ans + ansRec) % MOD;
                }
                  dp[index][t] = ans;
            }
        }
        return dp[n][target];

    }

    int solveUsingTabulationSO(int n ,int k ,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1 , 0 ));

        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0] = 1;

        for(int index = 1 ; index <= n ;index++){
            for(int t= 1;t<=target;t++){
                long long int ans = 0 ;
                for(int i=1;i<=k;i++){
                    long long int ansRec = 0 ;
                    if(t- i >=0)
                       ansRec = prev[t-i];
                    ansRec  = ansRec % MOD;
                    ans  = ans%MOD ;
                    ans = (ans + ansRec) % MOD;
                }
                  curr[t] = ans;
            }
            // shift
            prev = curr;
        }
        return curr[target];

    }
    

    int numRollsToTarget(int n, int k, int target) {
        // return solveUsingRecursion(n,k,target);
        // vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        // return solveUsingMem(n,k,target,dp);

        return solveUsingTabulationSO(n,k,target);
    }
};