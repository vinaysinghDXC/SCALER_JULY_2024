// https://www.scaler.com/academy/mentee-dashboard/class/297881/homework/problems/4099?navref=cl_tt_nv

// Problem Description

// Given an integer A, find and return the total number of digit 1 appearing in all non-negative integers less than or equal to A.



// Problem Constraints

// 0 <= A <= 109



// Input Format

// The only argument given is the integer A.



// Output Format

// Return the total number of digit 1 appearing in all non-negative integers less than or equal to A.



// Example Input

// Input 1:

//  A = 10
// Input 2:

//  A = 11


// Example Output

// Output 1:

//  2
// Output 2:

//  4


// Example Explanation

// Explanation 1:

// Digit 1 appears in 1 and 10 only and appears one time in each. So the answer is 2.
// Explanation 2:

// Digit 1 appears in 1(1 time) , 10(1 time) and 11(2 times) only. So the answer is 4.

int Solution::solve(int A) {
    long long count = 0;
    long long factor = 1;  //the current digit position (1's, 10's, 100's, ....)

    while (A / factor > 0) {
        long long lower = A - (A / factor) * factor;  //after the current position
        long long current = (A / factor) % 10;        //digit to be analyzed
        long long higher = A / (factor * 10);         //before the current position

        //the current digit is 0, the count of '1's in this position is determined by the higher part
        if (current == 0) {
            count += higher * factor;
        }
        //the current digit is 1, the count of '1's in this position includes all higher part combinations
        // and the numbers formed by the lower part
        else if (current == 1) {
            count += higher * factor + lower + 1;
        }
        //the current digit is greater than 1, count all numbers in this position (higher + 1) * factor
        else {
            count += (higher + 1) * factor;
        }

        factor *= 10;
    }

    return count;
}
