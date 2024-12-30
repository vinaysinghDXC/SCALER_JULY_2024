// Problem Description

// Misha likes finding all Subarrays of an Array. Now she gives you an array A of N elements and told you to find the number of subarrays of A, that have unique elements.

// Since the number of subarrays could be large, return value % 109 +7.



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= 106



// Input Format

// The only argument given is an Array A, having N integers.



// Output Format

// Return the number of subarrays of A, that have unique elements.



// Example Input

// Input 1:

//  A = [1, 1, 3]
// Input 2:

//  A = [2, 1, 2]


// Example Output

// Output 1:

//  4
// Output 1:

//  5


// Example Explanation

// Explanation 1:

//  Subarrays of A that have unique elements only:
//  [1], [1], [1, 3], [3]
// Explanation 2:

//  Subarrays of A that have unique elements only:
//  [2], [1], [2, 1], [1, 2], [2]

//<CODE>
int Solution::solve(vector<int> &A) {
    int MOD = 1e9+7;
    int n = A.size();
    vector<int> freq(1000001,0);  // Assuming elements are within the range [1, 1000000]
    int left = 0, right = 0;
    long long count = 0;

    while (right < n) {
        // freq[A[right]]++;
        
        while (freq[A[right]] >= 1) {
            freq[A[left]]--;
            left++;
        }
        count = (count + (right - left) + 1)%MOD;
        freq[A[right]]++;
        right++;
    }
    return count;
}
