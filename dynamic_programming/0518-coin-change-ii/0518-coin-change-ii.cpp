class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<double> dp(amount + 1 , 0);
        dp[amount] = 1 ; 
        for(int i=coins.size()-1;i>=0 ; i--){
            for(int j=amount ; j>=0 ;j--){
                if(j+coins[i]<=amount){
                    dp[j] = dp[j] +  dp[j+coins[i]];
                }
            }
        }

        return dp[0] ; 
    }
};