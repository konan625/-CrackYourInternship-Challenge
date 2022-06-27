You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        while(j<n){
            pq.push(make_pair(nums[j],j));
            if(j-i+1<k)j++;
            else if(j-i+1==k){
                while(pq.top().second<i){
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;
                j++;
            }
        }
        return ans;   
    }
};

//Using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        while(j<n){
            
            while(dq.size() && dq.front()<nums[j]){
                dq.pop_front();
            }
            while(dq.size() && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;   
    }
};