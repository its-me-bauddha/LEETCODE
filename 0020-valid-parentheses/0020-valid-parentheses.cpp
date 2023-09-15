class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];

            // opening brackets
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else
            {
                //closing brackets 
                if(!st.empty()){
                    char topCh = st.top();
                    if(ch == ')' && topCh == '(' ){
                        // matching brackets
                        st.pop();
                    }
                    else if(ch == ']' && topCh == '[' ){
                        // matching brackets
                        st.pop();
                    }
                    else if(ch == '}' && topCh == '{' ){
                        // matching brackets
                        st.pop();
                    }
                    else {
                        //no matching brackets
                        return false;
                    }
                }
                else{

                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
        
    }
};