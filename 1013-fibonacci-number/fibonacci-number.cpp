class Solution {
public:
    int fib(int n) {
        int arr[100];
        arr[0] = 0 ;
        arr[1] = 1; 
        for(int i = 2 ; i <= n ; i++){
            arr[i] =  arr[i-1] + arr[i-2];
        } 
        return arr[n];
    }
};