class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       int ans=0,i=0,j=n-1,leftmx=0,rightmx=0;
       while(i<=j){
           if(height[i]<=height[j]){
               if(height[i]>leftmx)leftmx=height[i];
               else{
                   ans+=leftmx-height[i];
                   i++;
               }
           }
           else{
               if(height[j]>rightmx)rightmx=height[j];
               else{
                   ans+=rightmx-height[j];
                   j--;
               }
           }
       }
       return ans; 
    }
};