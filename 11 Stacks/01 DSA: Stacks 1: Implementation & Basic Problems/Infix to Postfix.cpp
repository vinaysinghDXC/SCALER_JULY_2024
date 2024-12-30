// https://www.scaler.com/academy/mentee-dashboard/class/236118/homework/problems/4353?navref=cl_tt_nv

// Problem Description

// Given string A denoting an infix expression. Convert the infix expression into a postfix expression.


// String A consists of ^, /, *, +, -, (, ) and lowercase English alphabets where lowercase English alphabets are operands and ^, /, *, +, - are operators.

// Find and return the postfix expression of A.

// NOTE:

// ^ has the highest precedence.
// / and * have equal precedence but greater than + and -.
// + and - have equal precedence and lowest precedence among given operators.



// Problem Constraints

// 1 <= length of the string <= 500000



// Input Format

// The only argument given is string A.



// Output Format

// Return a string denoting the postfix conversion of A.



// Example Input

// Input 1:

//  A = "x^y/(a*z)+b"
// Input 2:

//  A = "a+b*(c^d-e)^(f+g*h)-i"


// Example Output

// Output 1:

//  "xy^az*/b+"
// Output 2:

//  "abcd^e-fgh*+^*+i-"


// Example Explanation

// Explanation 1:

//  Ouput dentotes the postfix expression of the given input.

int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;
        
    return 0;
}

string Solution::solve(string A) {
    int i = 0;
    string postfix = "";
    stack <int>s;

    while(A[i]!='\0')
    {
        if(A[i]>='a' && A[i]<='z'|| A[i]>='A'&& A[i]<='Z')          
        {
            postfix += A[i];
            i++;
        }

        else if(A[i]=='(')
        {
            s.push(A[i]);
            i++;
        }

        else if(A[i]==')')
        {
            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.empty() && priority(A[i]) <= priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(A[i]);
            i++;
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }

    return postfix;
}
