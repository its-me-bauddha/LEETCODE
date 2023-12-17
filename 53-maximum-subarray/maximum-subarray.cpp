class Solution {
public:
    int maxArrayHelper(vector<int> &nums ,int start ,int end){
        if(start == end) return nums[start];

        int maxLeftBorderSum = INT_MIN , maxRightBorderSum = INT_MIN;
        int mid = start + ((end - start)>>1);

        int maxLeftSum = maxArrayHelper(nums,start,mid);
        int maxRightSum = maxArrayHelper(nums,mid+1,end);

        // max cross border sum 
        int leftBorderSum = 0 , rightBorderSum = 0;
        for(int i= mid; i >= start ; i--){
                 leftBorderSum += nums[i];
                 if( leftBorderSum > maxLeftBorderSum) maxLeftBorderSum = leftBorderSum;
        }
        for(int i= mid+1; i<=end ; i++){
                 rightBorderSum += nums[i];
                 if( rightBorderSum > maxRightBorderSum) maxRightBorderSum = rightBorderSum;
        } 

        int crossBorderSum = maxRightBorderSum + maxLeftBorderSum;
        return max(maxLeftSum ,max(maxRightSum,crossBorderSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxArrayHelper(nums, 0 ,nums.size()-1);
    }
};