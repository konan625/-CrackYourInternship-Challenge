//Brute
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int n=height.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int water=min(height[i],height[j])*abs(i-j);
                if(ans<water){
                    ans=water;
                }
            }
        }
        return ans;
            
    }
};

//Optimised
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int ans=INT_MIN;
        while(i<j){
            if(height[i]<=height[j]){
                ans=max(ans,abs(i-j)*min(height[j],height[i]));
                i++;
            }else{
                ans=max(ans,abs(i-j)*min(height[i],height[j]));
                j--;
            }
        }
        return ans;
        
    }
};