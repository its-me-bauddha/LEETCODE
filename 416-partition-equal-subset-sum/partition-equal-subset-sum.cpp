class Solution {
public:
    bool solveUsingRecursion(vector<int>& nums,int target,int index){
        //base case 
        if(target == 0) return 1;
        if(index >= nums.size() || target < 0 ) return 0;

        bool include = solveUsingRecursion(nums,target-nums[index],index+1);
        bool  exclude= solveUsingRecursion(nums,target,index+1);

        return include ||exclude;
    }
    bool solveUsingMem(vector<int>&nums,vector<vector<int> > &dp,int target,int index){
         //base case 
        if(target == 0) return 1;
        if(index >= nums.size() || target < 0 ) return 0;
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool include = solveUsingMem(nums,dp,target-nums[index],index+1);
        bool exclude= solveUsingMem(nums,dp,target,index+1);

        dp[index][target] =  include ||exclude;
        return dp[index][target];
    }
    bool solveUsingTab(vector<int>& nums,int target){
         int n =nums.size() ;
        vector<vector<int> >dp(n+1,vector<int>(target+1,0));
       
        for(int i=0;i<n;i++){
            dp[i][0] =  1;
        }

        for(int index=n-1;index>=0;index--){
            for(int t = 1;t<=target;t++){
                 bool include = 0 ;
                if(t-nums[index] >= 0)
                  include = dp[index+1][t-nums[index]];
                bool exclude=  dp[index+1][t];
                dp[index][t] =  include ||exclude;
       
            }
        }
         return dp[0][target];
    }
    bool solveSpaceOpt(vector<int>& nums,int target){
         int n =nums.size() ;

        vector<bool>curr(target+1,0);
        vector<bool>next(target+1,0);
       
        curr[0] = 1;
        next[0] = 1;

        for(int index=n-1;index>=0;index--){
            for(int t = 1;t<=target;t++){
                 bool include = 0 ;
                if(t-nums[index] >= 0)
                  include = next[t-nums[index]];

                bool exclude =  next[t];

                curr[t] = ( include ||exclude);
       
            }
            //shift
            next = curr;
        }
         return curr[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            sum+=i;
        }
        // sum -> odd yha par galti karugaa
        if(sum & 1) return false;
        int target = sum/2;
        int index = 0;

       // bool ans = solveUsingRecursion(nums,target,index);
    //    int n = nums.size();
    //    vector<vector<int> > dp(n,vector<int>( target+1,-1));
    //    bool ans = solveUsingMem(nums,dp,target,index);
        bool ans = solveSpaceOpt(nums,target);
        return ans;
    }
};