class Solution {
public:
    int minInsertions(string s) {
        int n = s.size() ; 
        vector<int> dp(n , 0) ; 
        vector<int> row(n,0) ; 
        for(int i=n-2; i>=0 ; i--){
            for(int j=i+1 ; j<n ; j++){
                if(s[i]==s[j]){
                    row[j] = dp[j-1] ; 
                }
                else{
                    row[j] = 1 + min( dp[j],row[j-1]) ; 
                }
            }
            dp = row ; 
        }
        return dp[n-1] ; 
    }
};