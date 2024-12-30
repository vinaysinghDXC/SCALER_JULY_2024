// https://www.scaler.com/academy/mentee-dashboard/class/297857/homework/problems/373?navref=cl_tt_lst_sl

// Problem Description

// Given an array A of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible).

// Return the minimum number of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.



// Problem Constraints

// 1 <= length of(A) <= 100

// Sum of all the elements will not exceed 10,000.



// Input Format

// First and only argument is an integer array A.



// Output Format

// Return an integer denoting the minimum number of elements whose sign needs to be flipped.



// Example Input

// Input 1:

//  A = [15, 10, 6]
// Input 2:

//  A = [14, 10, 4]


// Example Output

// Output 1:

//  1
// Output 2:

//  1


// Example Explanation

// Explanation 1:

//  Here, we will flip the sign of 15 and the resultant sum will be 1.
// Explanation 2:

//  Here, we will flip the sign of 14 and the resultant sum will be 0.
//  Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there sign are not minimum.

// This problem is a variation of the Subset Sum problem, where you aim to partition the array such that the sum 
// of one subset is as close to half of the total sum as possible. The key is to minimize the absolute difference 
// between the two subsets and calculate the flips accordingly.


#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int> &A) {
    int n = A.size();

    int totalSum = 0;
    for (int num : A)
        totalSum += num;

    vector<bool> dp((totalSum / 2) + 1, false);
    vector<int> count((totalSum / 2) + 1, 0);
    dp[0] = true;

    for (int num : A) {
        for (int j = totalSum / 2; j >= num; j--) {
            if (dp[j - num]) {
                if (!dp[j]) {
                    dp[j] = true;
                    count[j] = count[j - num] + 1;
                } else {
                    count[j] = min(count[j], count[j - num] + 1);
                }
            }
        }
    }

    int closestSum = 0;
    for (int j = totalSum / 2; j >= 0; j--) {
        if (dp[j]) {
            closestSum = j;
            break;
        }
    }

    return count[closestSum];
}
