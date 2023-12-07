class Solution {
public:
    bool  checkPalindrom(string s,int low ,int high){
      
        while(low <high){
            if(s[low] != s[high]){
                return false;
            }else{
                low++;high--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
         
        int i = 0;
        int j = s.length()-1;

        while(i<j){
            if(s[i] == s[j] ){
                i++,j--;
            }else{
                //s[i] != s[j];
                // check palindrom ;
                // ith char remove
               bool ans1 = checkPalindrom(s,i+1,j);
               // jth char remvove;
               bool ans2 = checkPalindrom(s,i,j-1);
               
               return ans1 || ans2;
            }
        }
        return true;
    }
};