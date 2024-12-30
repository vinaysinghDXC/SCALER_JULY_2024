// https://www.scaler.com/academy/mentee-dashboard/class/297921/homework/problems/1095?navref=cl_tt_nv

// Problem Description

// A lucky number is a number that has exactly 2 distinct prime divisors.





// You are given a number A, and you need to determine the count of lucky numbers between the range 1 to A (both inclusive).







// Problem Constraints

// 1 <= A <= 50000



// Input Format

// The first and only argument is an integer A.



// Output Format

// Return an integer i.e the count of lucky numbers between 1 and A, both inclusive.



// Example Input

// Input 1:

//  A = 8
// Input 2:

//  A = 12


// Example Output

// Output 1:

//  1
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Between [1, 8] there is only 1 lucky number i.e 6.
//  6 has 2 distinct prime factors i.e 2 and 3.
// Explanation 2:

//  Between [1, 12] there are 3 lucky number: 6, 10 and 12.

int Solution::solve(int A) {
    if (A <= 5) return 0; 
    vector<int> countdiv(A + 1, 0);

    //mark prime divisors
    for (int i = 2; i <= A; i++) {
        if (countdiv[i] == 0) {
            for (int j = i; j <= A; j += i) {
                countdiv[j]++;
            }
        }
    }

    int luckyCount = 0;
    for (int i = 2; i <= A; i++) {
        if (countdiv[i] == 2) {
            luckyCount++;
        }
    }

    return luckyCount;
}
