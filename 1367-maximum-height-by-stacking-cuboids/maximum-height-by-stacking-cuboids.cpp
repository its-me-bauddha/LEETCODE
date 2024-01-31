class Solution {
public:
    bool check(vector<int>a,vector<int>b){
        if(b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
            return true;
        else 
            return false;
    }
    int lengthOfLISUsingSO(vector<vector<int>>& nums)
{
    int n = nums.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(nums[curr],nums[prev]))
            {
                include = nums[curr][2] + nextRow[curr + 1];
            }
            int exclude = nextRow[prev + 1];

            int ans = max(include, exclude);
            currRow[prev + 1] = ans;
        }

        // shift
        nextRow = currRow;
    }
    return nextRow[0];
}
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort  array
        for(auto &a : cuboids){
            sort(a.begin(),a.end());

        }

        // sort 2d array
        sort(cuboids.begin(),cuboids.end());

        //apply LIS logic
        int ans = lengthOfLISUsingSO(cuboids);
        return ans;
    }
};