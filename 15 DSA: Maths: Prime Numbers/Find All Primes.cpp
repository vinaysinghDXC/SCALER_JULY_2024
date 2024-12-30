// https://www.scaler.com/academy/mentee-dashboard/class/297921/assignment/problems/35398?navref=cl_tt_nv

// Problem Description

// Given an integer A. Find the list of all prime numbers in the range [1, A].


// Problem Constraints

// 1 <= A <= 106



// Input Format

// Only argument A is an integer.



// Output Format

// Return a sorted array of prime number in the range [1, A].



// Example Input

// Input 1:
// A = 7
// Input 2:
// A = 12


// Example Output

// Output 1:
// [2, 3, 5, 7]
// Output 2:
// [2, 3, 5, 7, 11]


// Example Explanation

// For Input 1:
// The prime numbers from 1 to 7 are 2, 3, 5 and 7.
// For Input 2:
// The prime numbers from 1 to 12 are 2, 3, 5, 7 and 11.

vector<int> Solution::solve(int A) {
    if (A < 2) return {};

    vector<int> prime(A + 1, 1);
    prime[0] = 0;
    prime[1] = 0;

    for (int i = 2; i * i <= A; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= A; j += i) {
                prime[j] = 0;
            }
        }
    }

    vector<int> result;
    for (int i = 2; i <= A; i++) {
        if (prime[i] == 1) {
            result.push_back(i);
        }
    }

    return result;
}
