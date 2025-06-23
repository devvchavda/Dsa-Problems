class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xors = 0 ; 
        for(int x : nums){
            xors = xors^x ; 
        }
        int res1 = 0 ; 
        int res2 = 0 ; 
        int mask = xors&(-xors) ; 
        for(int x : nums){
            if((x&mask) != 0){
                res1 = res1 ^ x ; 
            }
            else{
                res2 = res2 ^ x ; 
            }
        }

        return {res1,res2} ; 
    }
};