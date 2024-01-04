class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int size = nums[n-1];
        vector<int> mp (size + n ,0 );
        
        for(int i=0;i<n;i++){
            
            mp[nums[i]]++;
        }
        
        int minOperation = 0;
        for(int i= 0;i<mp.size();i++){
            if(mp[i] != 0 && mp[i] != 1){
                 if(mp[i] % 3 == 0){
                        minOperation += mp[i]/3;
                        mp[i] = 0;
                }
                else if(mp[i] % 3 == 1 || mp[i] % 3 == 2 ){
                       minOperation += mp[i]/3 + 1;
                        mp[i] = 0;
                }
                 
            }
        }
        for(int i= 0;i<mp.size();i++){
           if(mp[i] != 0) return -1;
        }
        return minOperation;
    }
};