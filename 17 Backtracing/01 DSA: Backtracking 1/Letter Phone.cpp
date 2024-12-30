// https://www.scaler.com/academy/mentee-dashboard/class/297897/homework/problems/147?navref=cl_tt_lst_nm

// Problem Description

// Given a digit string A, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.



// The digit 0 maps to 0 itself. The digit 1 maps to 1 itself.

// NOTE: Make sure the returned strings are lexicographically sorted.



// Problem Constraints

// 1 <= |A| <= 10



// Input Format

// The only argument is a digit string A.



// Output Format

// Return a string array denoting the possible letter combinations.



// Example Input

// Input 1:

//  A = "23"
// Input 2:

//  A = "012"


// Example Output

// Output 1:

//  ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
// Output 2:

//  ["01a", "01b", "01c"]


// Example Explanation

// Explanation 1:

//  There are 9 possible letter combinations.
// Explanation 2:

//  Only 3 possible letter combinations.

void makecombinations(string A, vector<string> &ans, string current, int idx, unordered_map<char, string>& digitMap){
    if (idx==A.length()){
        ans.push_back(current);
        return;
    }
    string possibleLetters = digitMap[A[idx]];

    for (char letter : possibleLetters) {
        current.push_back(letter);    //add letter to the current
        makecombinations(A, ans, current, idx + 1, digitMap);
        current.pop_back();   //remove the last letter
    }
}

vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string> digitMap = {
        {'0', "0"}, 
        {'1', "1"},
        {'2', "abc"}, 
        {'3', "def"},
        {'4', "ghi"}, 
        {'5', "jkl"},
        {'6', "mno"}, 
        {'7', "pqrs"},
        {'8', "tuv"}, 
        {'9', "wxyz"}
    };
    int idx=0;
    vector<string> ans;
    string current="";
    makecombinations(A, ans, current, idx, digitMap);
    return ans;
}
