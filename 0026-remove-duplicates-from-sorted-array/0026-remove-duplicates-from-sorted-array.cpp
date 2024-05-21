class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ind=1,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            else{
                nums[ind++]=nums[i];
            }
        }
        return ind;
    }
};