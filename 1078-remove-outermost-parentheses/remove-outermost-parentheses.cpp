class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n = s.length();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                if(!st.empty()){
                    ans+="(";
                }
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                    if(!st.empty()){
                        ans+=")";
                    }
                }
            }
        }
        return ans;
    }
};