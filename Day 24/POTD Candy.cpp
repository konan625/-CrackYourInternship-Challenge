There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
1. Do it in two directions.
2. The first loop makes sure children with a higher rating get more candy than its left neighbor; the second loop makes sure children with a higher rating get more candy than its right neighbor.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> c(n,1);
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                right[i]=right[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=c[i];
            sum+=(max(left[i],right[i]));
        }
        return sum;
        
        
    }
};