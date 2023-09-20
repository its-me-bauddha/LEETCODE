class Solution {
public:
    int maxDepth(string s) {
        int cnt=0; int maxi = 0;
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '(')
            {
                st.push(ch);
                cnt++;
                maxi = max(maxi,cnt);
            }
            if(!st.empty() && cnt !=0){
                if(ch == ')'){
                st.pop();
                cnt--;
             }
            }
            
        }
        return maxi;
    }
};