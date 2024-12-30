// https://www.scaler.com/academy/mentee-dashboard/class/236080/homework/problems/10754?navref=cl_tt_lst_sl

// Problem Description

// Given a number A, we need to find the sum of its digits using recursion.


// Problem Constraints

// 1 <= A <= 109


// Input Format

// The first and only argument is an integer A.


// Output Format

// Return an integer denoting the sum of digits of the number A.


// Example Input

// Input 1:

//  A = 46
// Input 2:

//  A = 11


// Example Output

// Output 1:

//  10
// Output 2:

//  2


// Example Explanation

// Explanation 1:

//  Sum of digits of 46 = 4 + 6 = 10
// Explanation 2:

//  Sum of digits of 11 = 1 + 1 = 2

int Solution::solve(int A) {
    if(A/10==0) return A%10;
    int sum=A%10;
    return sum+solve(A/10);
}
