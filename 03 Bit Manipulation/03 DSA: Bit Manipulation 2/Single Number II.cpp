// https://www.scaler.com/academy/mentee-dashboard/class/236094/assignment/problems/195?navref=cl_tt_nv

// Problem Description

// Given an array of integers, every element appears thrice except for one, which occurs once.

// Find that element that does not appear thrice.

// NOTE: Your algorithm should have a linear runtime complexity.

// Could you implement it without using extra memory?




// Problem Constraints

// 2 <= A <= 5*106

// 0 <= A <= INTMAX



// Input Format

// First and only argument of input contains an integer array A.



// Output Format

// Return a single integer.



// Example Input

// Input 1:

//  A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
// Input 2:

//  A = [0, 0, 0, 1]


// Example Output

// Output 1:

//  4
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  4 occurs exactly once in Input 1.
//  1 occurs exactly once in Input 2.

int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(int i=0; i<32; i++){
        int count=0;
        for (int j=0; j<A.size(); j++){
            if((A[j]&(1<<i))!=0) count++;
        }
        if(count%3 != 0){
            ans=ans|(1<<i);
        }
    }
    return ans;
}
