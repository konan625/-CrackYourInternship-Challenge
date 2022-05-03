//explanation link of math algo - https://leetcode.com/problems/happy-number/discuss/56919/Explanation-of-why-those-posted-algorithms-are-mathematically-valid
class Solution {
public:
    bool isHappy(int n) {
        long long sum=0;
        while(n>0){
            long long rem=n%10;
            sum=sum+(rem*rem);
            n=n/10;
        }
        if(sum==1){return true;}
        if(sum==4){return false;}
        return isHappy(sum);
    }
};

//Using cycle detection algorithm
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
//link to the explanation - go to the first comment https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)