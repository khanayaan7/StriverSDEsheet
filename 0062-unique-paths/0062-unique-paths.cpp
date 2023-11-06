class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans=0;
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)dp[i][j]=1;
                else{
                int right=0,bottom=0;
                if(j+1<n)right=dp[i][j+1];
                if(i+1<m)bottom=dp[i+1][j];
                dp[i][j]=right+bottom;
                }
            }
        }
        return dp[0][0];
    }
};