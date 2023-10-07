class Solution {
public:

    int leftmostIndex(vector<int>& nums, int target){
        int n = nums.size()-1;
        int start = 0;
        int end = n;
        int mid = (start +(end-start)/2);
        int index = -1;

        while(start <= end){
            if(nums[mid]==target){
                index = mid;
                end = mid-1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = (start +(end-start)/2);
        }
        return index;
    }

    int rightmostIndex(vector<int>& nums, int target){
         int n = nums.size()-1;
        int start = 0;
        int end = n;
        int mid = (start +(end-start)/2);
        int index = -1;

        while(start <= end){
            if(nums[mid]==target){
                index = mid;
                start = mid+1;
            }
            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = (start +(end-start)/2);
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        

        //using binary search

        int left = leftmostIndex(nums,target);
        int right = rightmostIndex(nums,target);

        vector<int> index;
        index.push_back(left);
        index.push_back(right);

        return index;
    }
};
