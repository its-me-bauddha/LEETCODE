class Solution {
public:
   
    int minOperations(string s) {
        int countEvenIndex = 0 ;
        int countOddIndex = 0;
        for(int i=0;i<s.size();i++){
            if(i%2 == 0 ){
                if(s[i] == '0'){
                   countOddIndex++; 
                }else {
                    countEvenIndex++;
                }
            }else{
                if(s[i] == '1'){
                    countOddIndex++;
                }else{
                    countEvenIndex++;
                }
            }
        }

        return min(countEvenIndex,countOddIndex);
    }
};