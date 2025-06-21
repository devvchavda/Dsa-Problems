class Solution {
public:
    void givecount(vector<int> &arr , int index , int target , vector<vector<int>> &ans , vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return ;  
        }
        if(index == arr.size() or target<0){
            return ;
        }

        givecount(arr,index+1 , target , ans , temp);
        temp.push_back(arr[index]);
        givecount(arr,index,target-arr[index] ,ans , temp);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ; 
        vector<int> temp ; 

        givecount(candidates , 0 , target , ans , temp);

        return ans;
    }
};