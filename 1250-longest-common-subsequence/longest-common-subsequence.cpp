class Solution {
public:
    int longestCS_helperRecursion(string &text1, string &text2,int i ,int j){
        
        if(i == text1.length()) return  0;
        if(j == text2.length()) return  0;

        if(text1[i] == text2[j])
        return 1 + longestCS_helperRecursion(text1,text2,i+1,j+1);
        else{
            int ans1 = longestCS_helperRecursion(text1,text2,i+1,j);
            int ans2 = longestCS_helperRecursion(text1,text2,i,j+1);
            return  max(ans1,ans2);
       }
    }

    int longestCS_solveMem(string &text1, string &text2,int i ,int j,vector<vector<int>>&dp){
        
        if(i == text1.length()) return  0;
        if(j == text2.length()) return  0;

        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j])
        dp[i][j] = 1 + longestCS_solveMem(text1,text2,i+1,j+1,dp);
        
        else{
            int ans1 = longestCS_solveMem(text1,text2,i+1,j,dp);
            int ans2 = longestCS_solveMem(text1,text2,i,j+1,dp);
            dp[i][j] =    max(ans1,ans2);
       }
       return dp[i][j];
    }

     int longestCS_solveTab(string &text1, string &text2){
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ans = 0;
                if(text1[i] == text2[j])
                ans = 1 + dp[i+1][j+1];
                else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
        
    }

    int longestCommonSubsequence(string text1, string text2) {
       
        int i = 0; int j = 0 ;
        // int n = text1.length();
        // int m = text2.length();
        // //  return longestCS_helperRecursion(text1,text2,i,j);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return longestCS_solveMem(text1,text2,i,j,dp);

        return longestCS_solveTab(text1,text2);
    }
};