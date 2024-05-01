class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> freq;
        int i=0,j=0,n=s.size(),ans=0;
        while(j<n){
            freq[s[j]]++;
            if(freq[s[j]]>1){
                while(freq[s[j]]>1){
                    freq[s[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};