// https://www.scaler.com/academy/mentee-dashboard/class/297881/assignment/problems/76?navref=cl_tt_nv

// Problem Description

// Given a positive integer A, return its corresponding column title as it appears in an Excel sheet.







// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 









// Problem Constraints

// 1 <= A <= 109



// Input Format

// First and only argument of input contains single integer A



// Output Format

// Return a string denoting the corresponding title.



// Example Input

// Input 1:

// A = 3
// Input 2:

 
// A = 27


// Example Output

// Output 1:

// "C"
// Output 2:

// "AA"


// Example Explanation

// Explanation 1:

 
// 3 corrseponds to C.
// Explanation 2:

//     1 -> A,
//     2 -> B,
//     3 -> C,
//     ...
//     26 -> Z,
//     27 -> AA,
//     28 -> AB 

string Solution::convertToTitle(int A) {
    string ans="";
    while(A!=0){
        int rem=A%26;
        A=A/26;

        if (rem==0){
            A=A-1;
            rem=26;
        }
        ans=(char)('A'+rem-1)+ans;
    }
    return ans;
}
