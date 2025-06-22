class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size() ; 
        int n = t.size() ; 
        vector<double> dp(n+1 , 0);
        dp[n] = 1 ; 
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=0 ; j<=n ; j++){
                if(j==n) dp[j] = 1 ; 
                else if(s[i]==t[j]){
                    dp[j] += dp[j+1];
                }
            }
        }

        return dp[0] ; 
    }
};