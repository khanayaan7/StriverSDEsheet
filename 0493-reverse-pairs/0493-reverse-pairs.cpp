class Solution {
public:
    int ans=0;
    void merge(vector<int>&arr,int low,int mid,int high) {
    vector<int> temp;
    int left = low;      
    int right = mid + 1;
    int i=low,j=mid+1;
    while(i<=mid){
        while(j<=high && arr[i]>2*1LL*arr[j])j++;
        ans+=j-mid-1;
        i++;
    }
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> & arr, int low,int high) {
    if (low >=high) return;
    int mid = low + (high-low)/2 ;
    mergeSort(arr, low, mid); 
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return ans;
    }
};