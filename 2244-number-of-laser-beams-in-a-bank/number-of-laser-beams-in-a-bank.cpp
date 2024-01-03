class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        vector<int>sum;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(bank[i][j] == '1'){
                   count++;
                }
               
            }
            if(count != 0){
                sum.push_back(count);
                count = 0;
            }
            
            
        }
        if(sum.size() == 0 ) return 0;
        int product = 0;
        for(int i=0;i<sum.size()-1;i++){
            product = product +  sum[i] * sum[i+1];
        }

        return product;
    }


};