Given two integers num and k, consider a set of positive integers with the following properties:

The units digit of each integer is k.
The sum of the integers is num.
Return the minimum possible size of such a set, or -1 if no such set exists.

Note:

The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
The units digit of a number is the rightmost digit of the number.
Input: num = 58, k = 9
Output: 2
Explanation:
One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
Another valid set is [19,39].
It can be shown that 2 is the minimum possible size of a valid set.
//using maths trick
https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/discuss/2168211/C%2B%2B-or-Short-and-easy-with-math
https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/discuss/2168461/Python-or-Math-or-Explained

As a variation of minimum number of coins 
https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/discuss/2168185/Coin-Change-Variation-or-Infinite-supply-DP-Pattern-or-CPP
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        for(int i=1;i<=10;i++){
            if(i*k % 10 == num%10 && i*k<=num){
                return i;
            }
        }
        return -1;
        
    }
};