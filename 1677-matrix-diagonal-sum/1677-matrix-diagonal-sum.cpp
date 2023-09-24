class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0 ;
        int sum1 = 0 ;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ;j < m ;j++){
                if(i == j && (i+j+1) != n ){
                    sum = sum + mat[i][j];
                }

                if((i+j) == n -1){
                    sum1 = sum1+mat[i][j];
                } 
            }
        }

        return sum1+sum;
    }
};