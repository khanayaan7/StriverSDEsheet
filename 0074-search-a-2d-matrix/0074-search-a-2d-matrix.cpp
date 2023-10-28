class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int n=grid.size(),m=grid[0].size();
        int low=0,high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int currval=grid[mid/m][mid%m];
            if(currval==target){
                return true;
            }
            else if(currval<target)low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};