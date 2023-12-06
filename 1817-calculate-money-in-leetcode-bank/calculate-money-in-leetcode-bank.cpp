class Solution {
public:
    int totalMoney(int n) {
        int low = 1;
        int x = low;
        int sum = 0;
        int i = 0 ;
        while(n--){
                if(i < 7){ 
                    cout << x << " ";
                    sum +=x;
                    x++;
                    i++;
                   // cout <<sum << " "; 
                    
                }
                else{
                    i = 0 ;
                    low++;
                    x = low;
                    sum += x;
                    x++, i++;
                    // sum +=x;
                    // x++;
                }
        }
        return sum;
    }
};