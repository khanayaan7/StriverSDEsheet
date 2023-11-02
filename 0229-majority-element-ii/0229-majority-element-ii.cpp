class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int cnt1=0,cnt2=0,cand1=1e9+2,cand2=1e9+2;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(cnt1==0 && curr!=cand2){
                cnt1++;cand1=curr;
            }
            else if(cnt2==0 && curr!=cand1){
                cnt2++;cand2=curr;
            }
            else if(curr==cand1)cnt1++;
            else if(curr==cand2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(cand1==nums[i])cnt1++;
            else if(cand2==nums[i])cnt2++;
        }
        if(cnt1>n/3)ans.push_back(cand1);
        if(cnt2>n/3)ans.push_back(cand2);
        return ans;
    }
};