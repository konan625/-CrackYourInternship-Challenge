https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/754726/JavaC%2B%2BPython-1-Lines
class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0) low+=1;
        int c=0;
        while(low<=high){
            c++;
            low+=2;
        }
        return c;
    }
};

class Solution {
public:
    int countOdds(int low, int high) {
        return (high+1)/2 - (low/2);
    }
};