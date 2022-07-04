You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int hh=horizontalCuts.size();
        int vh=verticalCuts.size();
        //max horizontal difference;
        int mxh=abs(0-horizontalCuts[0]);
        for(int i=0;i<hh-1;i++){
            mxh=max(mxh,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        mxh=max(mxh,h-horizontalCuts[hh-1]);
        //max vertical difference
        int mxv=abs(0-verticalCuts[0]);
        for(int i=0;i<vh-1;i++){
            mxv=max(mxv,verticalCuts[i+1]-verticalCuts[i]);
        }
        mxv=max(mxv,w-verticalCuts[vh-1]);
        return (long) mxh * mxv % 1000000007;
    }
};
//Integer overflow problem solved by using long 
 max_h and max_v are int.

(max_h * max_v) % mod
In this sentence, it first exec (max_h * max_v), here is the problem. We need a temporary variable to hold the result of the * operation, and the type of the temporary variable is int because our two operand are int. Finally, we got an integer overflow. This happened before you exec (long) type cast.

(long)max_h * max_v % 1000000007;
What this sentence do is that it first cast one of the two operand which is max_h to long, and then do the * operation.
At this time the type of temporary variable is long, because the type of operand is long and int respectively. So it would not be integer overflow.