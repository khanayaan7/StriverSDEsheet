class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,curr=m+n-1;
        if(m==0){nums1=nums2;return;}
        if(n==0)return;
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[curr--]=nums1[i--];
            }
            else{
                nums1[curr--]=nums2[j--];
            }
        }
        
    }
};