// https://www.scaler.com/academy/mentee-dashboard/class/297897/assignment/problems/139?navref=cl_tt_nv

// Problem Description

// Given an integer A pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*A.



// Problem Constraints

// 1 <= A <= 10



// Input Format

// First and only argument is integer A.



// Output Format

// Return a sorted list of all possible parenthesis.



// Example Input

// Input 1:

// A = 3
// Input 2:

// A = 1


// Example Output

// Output 1:

// [ "((()))", "(()())", "(())()", "()(())", "()()()" ]
// Output 2:

// [ "()" ]


// Example Explanation

// Explanation 1:

//  All paranthesis are given in the output list.
// Explanation 2:

//  All paranthesis are given in the output list.

void paranthesis(int &A, vector<string> &ans, int opens, int close, string current){
    if (current.length()==(2*A)){
        ans.push_back(current);
        return;
    }

    if (opens<A) {
        paranthesis(A, ans, opens+1, close, current+"(");
    }
    if (close < opens){
        paranthesis(A, ans, opens, close+1, current+")");
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    int opens=0;
    int close=0;
    string current="";
    paranthesis(A, ans, opens, close, current);
    return ans;
}
