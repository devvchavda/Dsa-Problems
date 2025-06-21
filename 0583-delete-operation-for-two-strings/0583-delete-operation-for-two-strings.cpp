class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() ; 
        int n = word2.size() ; 
        vector<int> dp(n+1 , 0) ; 
        for(int i=m ; i>=0 ; i--){
            int prev = -1;
            for(int j=n ; j>=0 ; j--){
                int oldprev = prev ; 
                prev = dp[j] ; 
                if(i==m and j==n) dp[j] = 0 ; 
                else if(i==m) dp[j] = n-j ; 
                else if(j==n) dp[j] = m-i ; 
                else if(word1[i] == word2[j]) dp[j] = oldprev ; 
                else{
                    dp[j] = 1 + min(dp[j+1] , prev) ; 
                }
            }
        }

        return dp[0] ; 
    }
};
