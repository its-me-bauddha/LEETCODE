class Solution {
public:
    int lengthOfLISUsingRecursion(vector<int>& nums ,int curr ,int prev){
          if(curr >= nums.size()) return 0;

            int include = 0;
            int exclude = 0;
            if(prev == -1  ||  nums[prev] < nums[curr]){
                 include = 1  +  lengthOfLISUsingRecursion(nums,curr+1,curr);
            }            
            exclude =   lengthOfLISUsingRecursion(nums,curr+1,prev);

            return   max(include ,exclude);
        }

    int lengthOfLISUsingMem(vector<int>& nums ,int curr ,int prev ,vector<vector<int>>& dp ){
          if(curr >= nums.size()) return 0;

            int include = 0;
          
            if(dp[curr][prev+1]  != -1 ) return dp[curr][prev+1];
            if(prev == -1  ||  nums[prev] < nums[curr]){
                 include = 1  +  lengthOfLISUsingMem(nums,curr+1,curr,dp);
            }            
           int  exclude =   lengthOfLISUsingMem(nums,curr+1,prev,dp);

          int ans =  max(include ,exclude);
           dp[curr][prev +1] = ans ;
           return dp[curr][prev+1];
        }

    
    int lengthOfLISUsingTab(vector<int>& nums){
            int n = nums.size();
           vector<vector<int>>dp(n+4,vector<int>(n+4,0));

            for(int curr =n - 1;curr >=0 ;curr--){
                for(int prev =curr-1; prev >= -1 ;prev-- ){
                    int include = 0 ;
                    if(prev == -1  ||  nums[prev] < nums[curr]){
                    include = 1  +  dp[curr+1][curr+1];
                   }            
                   int  exclude =   dp[curr+1][prev+1];

                    int ans =  max(include ,exclude);
                    dp[curr][prev+1] = ans ;
           
                }
            }
            return dp[0][0];
        }

    int lengthOfLISUsingSO(vector<int>& nums){
            int n = nums.size();
            vector<int> currRow(n+1,0);
            vector<int> nextRow(n+1,0);

            for(int curr =n - 1;curr >=0 ;curr--){
                for(int prev =curr-1; prev >= -1 ;prev-- ){
                    int include = 0 ;
                    if(prev == -1  ||  nums[prev] < nums[curr]){
                    include = 1  +  nextRow[curr+1];
                   }            
                   int  exclude =   nextRow[prev+1];

                    int ans =  max(include ,exclude);
                    currRow[prev+1] = ans ;
           
                }

                // shift
                nextRow = currRow;
            }
            return nextRow[0];
        }

    int lengthOfLIS(vector<int>& nums) {
            int curr = 0;
            int prev = -1;

            // int ans =  lengthOfLISUsingRecursion(nums,curr,prev);
           
              int ans =  lengthOfLISUsingSO(nums);
            return ans;     
    }
};