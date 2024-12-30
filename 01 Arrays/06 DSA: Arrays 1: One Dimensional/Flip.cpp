// https://www.scaler.com/academy/mentee-dashboard/class/236078/homework/problems/329?navref=cl_tt_nv

// Problem Description

// You are given a binary string A(i.e., with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices, L and R, such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean changing character 0 to 1 and vice-versa.





// Your aim is to perform ATMOST one operation such that in the final string number of 1s is maximized.

// If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

// NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.







// Problem Constraints

// 1 <= size of string <= 100000



// Input Format

// First and only argument is a string A.



// Output Format

// Return an array of integers denoting the answer.



// Example Input

// Input 1:

// A = "010"
// Input 2:

// A = "111"


// Example Output

// Output 1:

// [1, 1]
// Output 2:

// []


// Example Explanation

// Explanation 1:

// A = "010"

// Pair of [L, R] | Final string
// _______________|_____________
// [1 1]          | "110"
// [1 2]          | "100"
// [1 3]          | "101"
// [2 2]          | "000"
// [2 3]          | "001"

// We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
// Explanation 2:

// No operation can give us more than three 1s in final string. So, we return empty array [].

vector<int> Solution::flip(string A) {
    int n = A.size();
    vector<int> transform(n);
    
    for (int i = 0; i < n; ++i) {
        if (A[i] == '0') {
            transform[i] = 1;
        } else {
            transform[i] = -1;
        }
    }
    
    // SApply Kadane's algorithm to find the maximum subarray sum
    int max_sum = INT_MIN, current_sum = 0;
    int start = 0, end = 0, temp_start = 0;
    
    for (int i = 0; i < n; ++i) {
        current_sum += transform[i];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
        
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }
    
    // If max_sum is non-positive, no flip will increase the number of 1's
    vector<int> ans;
    if (max_sum <= 0) {
        return ans;
    }
    
    // Return the 1-based indices of the subarray to flip
    ans.push_back(start + 1);
    ans.push_back(end + 1);
    return ans;
}
