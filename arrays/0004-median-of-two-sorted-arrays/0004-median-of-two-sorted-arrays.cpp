class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size() ; 
        int n = nums2.size() ; 
        int length = m+n ; 

        int value1 , value2 ; 
        int index = length/2 ; 
        int i = 0 ;
        int j = 0 ;
        for(int k=0 ; k<=index ; k++){
            value1 = value2 ; 
            if(i<m && (j>=n || nums1[i] <= nums2[j])){
                value2 = nums1[i];
                i++;
            }
            else{
                value2 = nums2[j];
                j++ ; 
            }
        }
        
        if((length % 2 != 0)){
            return value2 ; 
        }
        else{
            return double((value1 + value2)*0.5);
        }
        return -1;
    }
};