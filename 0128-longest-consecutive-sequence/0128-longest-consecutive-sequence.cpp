class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ms(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums){
            if(ms.count(it-1)==0){
                int curr=1,temp=it+1;
                while(ms.count(temp)){
                    curr++;
                    temp++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};