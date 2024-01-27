class Solution {
public:
    int solveUsingRecursion(vector<int>& arr ,map<pair<int,int>,int> &maxi , int left,int right){
         // base case
         if(left == right) return 0;

         int ans= INT_MAX;
         for(int i = left ;i<right;i++){
             ans = min(ans,
             maxi[{left,i}] * maxi[{i+1 ,right}] +
              solveUsingRecursion(arr,maxi,left,i) +
              solveUsingRecursion(arr,maxi,i+1,right) );
        
        }
        return ans;
    }
    int solveUsingMem(vector<int>& arr ,map<pair<int,int>,int> &maxi , int left,int right,vector<vector<int>>&dp){
         // base case
         if(left == right) return 0;
            if(dp[left][right] != -1) return dp[left][right];
         int ans= INT_MAX;
         for(int i = left ;i<right;i++){
             ans = min(ans,
             maxi[{left,i}] * maxi[{i+1 ,right}] +
              solveUsingMem(arr,maxi,left,i,dp) +
              solveUsingMem(arr,maxi,i+1,right,dp) );
        
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    int mctFromLeafValues(vector<int>& arr) {
      map < pair <int,int > , int> maxi;

        //pre -computation
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}] = max(arr[j] , maxi[{i,j-1}]);
            }
        }


        int n = arr.size();
        // int ans = solveUsingRecursion(arr,maxi,0,n-1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveUsingMem(arr,maxi,0,n-1,dp);
        return ans;
    }
};