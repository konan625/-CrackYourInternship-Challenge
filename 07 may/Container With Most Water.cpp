// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int n=height.size();
        int i=0,j=n-1;
        ans=min(height[i],height[j])*abs(i-j);
        while(i<j){
            if(height[i]<height[j]){
                i++;
                ans=max(ans,min(height[i],height[j])*abs(i-j));
            }
            else if(height[i]>=height[j]){
                j--;
                ans=max(ans,min(height[i],height[j])*abs(i-j));
            }
        }
        return ans;     
    }
};
https://www.youtube.com/watch?v=UuiTKBwPgAo