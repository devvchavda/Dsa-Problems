class Solution {
public:
    int numSquares(int n) {
        int k = floor(sqrt(n)) + 1 ;
        vector<int> dp(n+1 , INT_MAX) ; 
        dp[n] = 0 ; 
        for(int i=k ; i>=1 ; i--){
            vector<int> row(n+1,INT_MAX) ; 
            for(int j=n ; j>=0 ; j--){
                int take = INT_MAX ; 
                int nottake = INT_MAX ; 
                if(j + i*i <= n and row[j+i*i]!=INT_MAX){
                    take = 1 + row[j+i*i];
                }
                nottake = dp[j] ; 
                row[j] = min(take,nottake) ; 
            }
            dp = row;
        }

        return dp[0] ; 
    }
};