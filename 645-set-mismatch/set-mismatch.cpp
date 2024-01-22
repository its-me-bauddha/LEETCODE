class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
     
        int n = nums.size();
        vector<int> arr(n+1,0);
        int numIndex = 0;
        int repeatedNum = 0;
      
      

    for(int i=0;i<n;i++){
        arr[nums[i]]++;
    }

    for(int i=1;i<arr.size();i++){
        if(arr[i] == 2) repeatedNum = i;
        if(arr[i] == 0 ) numIndex = i;
        
    }
      return {repeatedNum,numIndex};
    }
    
};