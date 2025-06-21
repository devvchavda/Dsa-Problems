class Solution {
public:
    int binarysearch(int val , vector<int> &nums , int start){
        int end = nums.size()-1 ; 
        int ans = end + 1;  
        while(start<=end){
            int mid = start + (end-start)/2 ; 
            if(nums[mid]<=val){
                start = mid + 1 ; 
            }
            else{
                ans = mid; 
                end = mid-1 ; 
            }
        }
        return ans ; 
    }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()) ; 
        int i = 0 ; 
        vector<vector<int>> ans ; 
        while(i<nums.size()){
            int j = binarysearch(nums[i]+k,nums,i) ; 
            if(j-i < 3){
                return {} ; 
            }
            vector<int> temp ; 
            for(int k = 0 ; k<3 ; k++){
                temp.push_back(nums[i++]);
            }
            ans.push_back(temp);
        }


        return ans ; 
    }
};