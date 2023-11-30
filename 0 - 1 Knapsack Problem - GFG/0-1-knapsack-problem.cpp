//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int> (W+1,0));
    //   if(W>=wt[0]){
    //       for(int i=wt[0];i<=W;i++){
    //           dp[0][i]=val[0];
    //           }
    //   }
        for(int i=0;i<n;i++){
            for(int j=0;j<=W;j++){
                if(i==0){
                    int pick=0;
                    if(wt[i]<=j)pick=val[i];
                    dp[i][j]=pick;
                }
                else{
                int pick=-1e9;
                if(wt[i]<=j)
                pick=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(pick,dp[i-1][j]);
                }
            }
        }
        return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends