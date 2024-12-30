// https://www.scaler.com/academy/mentee-dashboard/class/236118/homework/problems/274?navref=cl_tt_nv

// Problem Description

// Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.


// Check whether A has redundant braces or not.

// NOTE: A will be always a valid expression and will not contain any white spaces.



// Problem Constraints

// 1 <= |A| <= 105



// Input Format

// The only argument given is string A.



// Output Format

// Return 1 if A has redundant braces else, return 0.



// Example Input

// Input 1:


//  A = "((a+b))"
// Input 2:

//  A = "(a+(a+b))"






// Example Output

// Output 1:


//  1
// Output 2:

//  0



// Example Explanation

// Explanation 1:


//  ((a+b)) has redundant braces so answer will be 1.
// Explanation 2:

//  (a+(a+b)) doesn't have have any redundant braces so answer will be 0.

int Solution::braces(string A) {
    stack<char> st;
 
    for (auto& ch : A) {
        if (ch == ')') {
            char top = st.top();
            st.pop();
            int flag = 1;
            while (!st.empty() and top != '(') {
                if (top == '+' || top == '-' || 
                    top == '*' || top == '/')
                    flag = 0;
 
                top = st.top();
                st.pop();
            }
 
            if (flag == 1)
                return 1;
        }
        else
            st.push(ch);
    }
    return 0;
}
