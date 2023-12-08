class Solution {
public:
vector<int> previousSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());

    for (int i = 0; i < v.size(); i++)
    {

        int curr = v[i];

        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> nextSmaller(vector<int> &v)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];

        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

    int largestRectangleArea(vector<int>& height) {
        vector <int> prev =previousSmaller(height);
    vector<int> next =nextSmaller(height);

    int maxArea = INT_MIN;
    int size = height.size();

    for(int i=0;i<height.size();i++){
        int length = height[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i]-prev[i] -1;

        int area = length*width;
        maxArea = max(maxArea,area);

    }
    return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> v; 
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            vector<int> t ;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j] -'0');
            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                // update curr row with prev value
                if(v[i][j]){
                    v[i][j] += v[i-1][j];
                }
                else{
                     v[i][j] = 0;
                }
            }
            area = max(area,largestRectangleArea(v[i]));
        }
        return area;
        
    }
};