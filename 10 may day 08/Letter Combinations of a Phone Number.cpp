// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
class Solution {
public:
    map<int, string> m {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };
    vector<string> ans;
    void helper(string digits,string &currentstring,int i){
        if(i==digits.size()){ans.push_back(currentstring); return;}
        for(auto x: m[digits[i]-'0']){
            currentstring+=x;
            helper(digits,currentstring,i+1);
            currentstring.pop_back();
        }   
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return ans;
        }
        string currentstring="";
        helper(digits,currentstring,0);
        return ans;
    }
};