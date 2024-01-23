class Solution {
public:
    bool compareChar(vector<int>& selected ,string& currString){
        vector<int>selfCheck(26,0);
        for(int i=0;i<currString.size();i++){
           if(selfCheck[currString[i] - 'a'] == 1) return false; 
            selfCheck[currString[i] - 'a'] = 1;
        }

        for(int i=0;i<currString.size();i++){
            if(selected[currString[i] - 'a'] == 1) return false;
        }
        return true;
    }
    int maxLength_helper(vector<string>& arr,vector<int>& selected,int len,int i){
        if(i == arr.size()) return len;
        string currString = arr[i];
        if(compareChar(selected,currString) == false){
            return maxLength_helper(arr,selected,len,i+1);
        }else{
            // pick the curr string
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 1;

            }
            len += currString.size();
            int opt1 = maxLength_helper(arr,selected,len,i+1);

            // skip
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 0;

            }
            len -= currString.size();
             int opt2 = maxLength_helper(arr,selected,len,i+1);
             return max(opt1,opt2);
        }
        
    }   
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
         return maxLength_helper(arr,selected,0,0);
        
    }
};