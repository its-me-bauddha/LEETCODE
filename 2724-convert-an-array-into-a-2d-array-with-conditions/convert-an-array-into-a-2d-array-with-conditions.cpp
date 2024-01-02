class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result ;
        vector<int>mp(n+1,0);  // store the frequecy 

        for(int i=0;i<n;i++){
            int freq = mp[nums[i]]; //  freq of the element

            if(freq == result.size()){
                result.push_back({}); // insert the row if the element is already present 
                                    // in the prevoius rows
            }
            
                result[freq].push_back(nums[i]);
                mp[nums[i]]++; // increment the freq of the element
           
        }
        return result;

    }
};