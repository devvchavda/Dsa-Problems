class Solution {
public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size() ;
        int n = s2.size() ; 
        vector<int> dp(n+1 , 0);
        vector<int> row(n+1 , 0);
        for(int i=n; i>=0 ; i--){
            dp[i] = n - i ; 
        }
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n ; j>=0 ; j--){
                if(j==n){
                    row[j] = 1 + dp[j];
                }
                else if(s1[i] == s2[j]){
                    row[j] = dp[j+1] ; 
                }
                else{
                    row[j] = min(min(1+ dp[j],1+dp[j+1]) , 1+row[j+1]) ; 
                }
            }
            dp = row ; 
        }
        
        return dp[0] ; 
        
    }
    int minDistance(string word1, string word2) {
        return editDistance(word1,word2) ; 
    }
};