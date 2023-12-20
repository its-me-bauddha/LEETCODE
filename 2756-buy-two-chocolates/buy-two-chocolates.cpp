class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans = INT_MAX;;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < prices.size(); j++) {
                if (i != j ) {
                    int sum = prices[i] + prices[j];
                    ans = min(ans, sum);
                }
            }
        }
       
        int leftMoney = money - ans;
        if(leftMoney >=0){
        return leftMoney;
        }else
        return money;
    }
};