// https://www.scaler.com/academy/mentee-dashboard/class/236118/homework/problems/4218?navref=cl_tt_nv

// Problem Description

// Given two strings A and B. Each string represents an expression consisting of lowercase English alphabets, '+', '-', '(' and ')'.


// The task is to compare them and check if they are similar. If they are identical, return 1 else, return 0.

// NOTE: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’, and every operand appears only once.




// Problem Constraints

// 1 <= length of the each String <= 100



// Input Format

// The given arguments are string A and string B.



// Output Format

// Return 1 if they represent the same expression else return 0.



// Example Input

// Input 1:

//  A = "-(a+b+c)"
//  B = "-a-b-c"
// Input 2:

//  A = "a-b-(c-d)"
//  B = "a-b-c-d"


// Example Output

// Output 1:

//  1
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  The expression "-(a+b+c)" can be written as "-a-b-c" which is equal as B. 
// Explanation 2:

//  Both the expression are different.

vector<int> evaluateExpression(const string& expr) {
    stack<int> signStack;
    vector<int> result(26, 0);

    int sign = 1;
    signStack.push(1);

    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '+') {
            continue;
        } 
        else if (expr[i] == '-') {
            sign = -1;
        } 
        else if (expr[i] == '(') {
            signStack.push(signStack.top() * sign);
            sign = 1;
        } 
        else if (expr[i] == ')') {
            signStack.pop();
        } 
        else if (expr[i] >= 'a' && expr[i] <= 'z') {
            result[expr[i] - 'a'] += signStack.top() * sign;
            sign = 1;
        }
    }
    return result;
}

int Solution::solve(string A, string B) {
    vector<int> exprA = evaluateExpression(A);
    vector<int> exprB = evaluateExpression(B);
    
    for (int i = 0; i < 26; i++) {
        if (exprA[i] != exprB[i]) {
            return 0;
        }
    }
    return 1;
}
