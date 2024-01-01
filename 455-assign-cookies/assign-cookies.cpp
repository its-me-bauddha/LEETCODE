class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cNums = s.size();
        if(cNums ==0) return 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
       

        int maxi = 0;
        int cIndex = cNums - 1;
        int childIndex = g.size() -1;

       
        while(cIndex >= 0 && childIndex >= 0 ){
            if(s[cIndex] >= g[childIndex]){
                maxi++;
                cIndex-- ,childIndex--;
            }else{
                childIndex--;
            }
        }
        return maxi;
    }
};