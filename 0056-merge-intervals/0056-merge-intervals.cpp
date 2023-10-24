class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(),curr=0;
        for(int i=1;i<n;i++){
            int f=intervals[i][0];
            if(f>=intervals[curr][0] && f<=intervals[curr][1]){
                intervals[curr][1]=max(intervals[curr][1],intervals[i][1]);
            }
            else{
                ans.push_back({intervals[curr][0],intervals[curr][1]});
                curr=i;
            }
        }
        ans.push_back({intervals[curr][0],intervals[curr][1]});
        return ans;
    }
};