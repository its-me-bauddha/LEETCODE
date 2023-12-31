class Solution {
public:
    int  maxSubStr(string& s ,int start){
        char x = s[start-1];
        int index = start;
        int ans = -1;
        while(start < s.size()){
                if(s[start] == x){
                    ans = start;
                    start++;
                }else{
                    start++;
                }
        }
        if(ans != -1) return ans - index;
        else 
        return -1;
    }
    int maxLengthBetweenEqualCharacters(string s) {
        int maxi = -1;
        int n = s.size(); 
        for(int i=0;i<n-1;i++){
            int ans = maxSubStr(s,i+1);
            maxi = max(ans,maxi);
        }
        return maxi;
    }
};