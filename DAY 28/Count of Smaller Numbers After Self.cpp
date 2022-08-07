class Solution {
public:
    void merge(vector<pair<int,int>>& arr,int l , int r,int mid,vector<int>& ans){
        int i=l,j=mid+1,k=0;
        vector<pair<int,int>> temp(r-l+1);
        while(i<=mid && j<=r){
            if(arr[i].first>arr[j].first){
                ans[arr[i].second]+=(r-j+1);
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid) temp[k++]=arr[i++];
        while(j<=r) temp[k++]=arr[j++];
        k=0;
        for(int i=l;i<=r;i++){
            arr[i]=temp[k++];
        }
    }
    void mergesort(vector<pair<int,int>>& arr,int l , int r,vector<int>& ans){
        if(l<r){
            int mid=(l+r)/2;
            mergesort(arr,l,mid,ans);
            mergesort(arr,mid+1,r,ans);
            merge(arr,l,r,mid,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back(make_pair(nums[i],i));
        }
        vector<int> ans(n,0);
        mergesort(arr,0,n-1,ans);
        return ans;
    }
};

Using ascending order 
class Solution {
public:
    void merge(vector<pair<int,int>> &nums, int left, int mid, int right, vector<int> &counts){
        vector<pair<int, int>> temp(right-left+1);
        int i = left, j = mid+1, c = 0;
        int val = 0;
        while(i <= mid and j <= right){
            if(nums[i].first <= nums[j].first){
                counts[nums[i].second] += val;
                temp[c++] = nums[i++];
            }
            else{
                val++;
                temp[c++] = nums[j++];
            }
        }
        while(i <= mid){
            counts[nums[i].second] += val;
            temp[c++] = nums[i++];
        }
        while(j <= right){
            temp[c++] = nums[j++];
        }
        c = 0;
        for(int k = left; k <= right; k++){
            nums[k] = temp[c++];
        }
    }
    
    
    void mergeSort(vector<pair<int, int>> &nums, int left, int right, vector<int> &counts){
        if(left >= right){
            return;
        }
        int mid = (left + right)/2;
        mergeSort(nums, left, mid, counts);
        mergeSort(nums, mid+1, right, counts);
        merge(nums, left, mid, right, counts);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        // {value, index}
        vector<pair<int, int>> numsmap(nums.size());
        for(int i = 0; i < n; i++){
            numsmap[i] = make_pair(nums[i], i);
        }
        vector<int> counts(n, 0);
        mergeSort(numsmap, 0, n-1, counts);
        return counts;
    }
};