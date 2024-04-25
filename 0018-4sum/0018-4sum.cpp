class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){       
                long long curr =target*1LL-nums[i]-nums[j]*1LL;
                int low =j+1,high=n-1;
                while(low < high){
                    if(nums[low] + nums[high] < curr){
                        low++;
                    }
                    else if(nums[low] + nums[high] > curr){
                        high--;
                    }
                    else{
                        ans.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }
        vector<vector<int>> nans;
        for(auto it:ans){
            nans.push_back(it);
        }
        return nans;
    }
};