class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size() ; 
        int n = s2.size() ; 
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0) ) ; 
        for(int i=m-1; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1] ; 
                }
                else{
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1])  ;
                }
            }
        }
        int i = 0 ; 
        int j = 0 ; 
        string ans = ""; 
        while(i<m and j<n){
            if(s1[i] == s2[j]){
                ans.push_back(s1[i]);
                i++;
                j++;
            }
            else{
                if(dp[i+1][j] >= dp[i][j+1]){
                    ans.push_back(s1[i]);
                    i++;
                }
                else{
                    ans.push_back(s2[j]);
                    j++;
                }
            }
        }
        while(i<m){
            ans.push_back(s1[i]);
            i++;    
        }
        while(j<n){
            ans.push_back(s2[j]);
            j++; 
        }

        return ans ; 
    }
};