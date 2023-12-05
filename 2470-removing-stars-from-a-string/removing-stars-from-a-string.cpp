class Solution {
public:
    string removeStars(string s) {
        
        stack <char> st;
        for(char ch : s){
            if(ch == '*' && !st.empty()){
                    st.pop(); 
            }
            else{
                st.push(ch);
            }
        }

        string ans ="";
        while(!st.empty()){
            char temp = st.top();
            ans +=temp;
            st.pop();
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};