class Solution {
public:
    int n ;
    int optimal(){
        int count = 0 ; 
        while(n%2 == 0){
            count += 2 ; 
            n = n/2 ; 
        }
        for(int i=3;i*i<=n ; i = i+2){
            while(n%i == 0){
                count += i ; 
                n = n/i ;
            }
        }
        if(n>1){
            count += n ; 
        }

        return count ; 
    }
    int recurse(int len , int copy , vector<vector<int>> &dp){
        if(n==len){
            return 0 ;
        }
        if(dp[len][copy]!=-1) return dp[len][copy] ; 
        int notcopy = INT_MAX ;
        int cpy = INT_MAX ; 
        if(len + copy <=n and copy!=0){
            notcopy = recurse(len+copy , copy , dp);
        }
        if(len!=copy){
            cpy = recurse(len,len,dp);
        }
        if(cpy == INT_MAX and notcopy==INT_MAX){
            return dp[len][copy] = INT_MAX ; 
        }

        return dp[len][copy] = 1 + min(cpy,notcopy) ;

    }
    int minSteps(int n) {
        if(n==1) return 0 ; 
        if(n==2 or n==3) return n ; 
        this->n = n ;   
        return optimal() ; 
    }
};