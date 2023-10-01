class Solution {
public:
    string removeDuplicates(string s) {
    
        string str = "";
            stack <char> st;
            st.push(s[0]);
            for(int i=1;i<s.size();i++){
                char ch = s[i];
                if(st.empty()){
                    st.push(ch);
                }
                else{
                    char x = st.top();
                    if(ch == x){
                    st.pop();
                    }
                    else{
                    st.push(ch);
                    }
                }
                
            }

            while(!st.empty()){
                str.push_back(st.top());
                st.pop();
            }
            reverse(str.begin(),str.end());
            return str;
    }
};