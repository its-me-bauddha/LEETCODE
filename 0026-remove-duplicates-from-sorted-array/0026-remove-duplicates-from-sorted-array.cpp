class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int high = 1;
        int cnt= 0;
    
        vector<int>ans;
        while(high <nums.size()){
            if(nums[low] == nums[high]){
                nums[low] = INT_MAX;
                low++;
                high++;     
            }
            else{
                low++;
                high++;
            }
        }
    //    // sort(nums.begin(),nums.end());
        
    //     for(int i = 0 ;i< nums.size() ;i++){
    //         if(nums[i] == -1){
    //             cnt++;
    //         }
    //     }
    //     for(int i = cnt;i< nums.size() ;i++){
    //        ans.push_back(nums[i]);
    //     }
    //     return nums.size();
    low =0 ;
    high = nums.size()-1;
    while(low<high){
        if(nums[low] != INT_MAX && nums[high] != INT_MAX)
        {
            low++;
        }
        else if(nums[low] != INT_MAX && nums[high] == INT_MAX)
        {
            low++;
        }
        else if(nums[low] == INT_MAX && nums[high] != INT_MAX)
        {
            swap(nums[low],nums[high]);
            low++,high--;
        }
        else{
            high--;
        }

    }
        for(int i = 0 ;i< nums.size() ;i++){
            if(nums[i] == INT_MAX){
                cnt++;
          }
        }
        sort(nums.begin(),nums.end());
        return nums.size()-cnt;
    }
};