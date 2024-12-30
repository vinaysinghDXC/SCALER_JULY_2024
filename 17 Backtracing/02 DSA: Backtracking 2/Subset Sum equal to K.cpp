// https://www.scaler.com/academy/mentee-dashboard/class/297913/assignment/problems/124896?navref=cl_tt_lst_nm

// Problem Description

// Given an integer array A of size N.


// You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

// If there exist a subset then return 1 else return 0.

// Note : Sum of elements of an empty subset is 0.




// Problem Constraints

// 1 <= N <= 17

// -109 <= A[i] <= 109

// -109 <= B <= 109



// Input Format

// First argument is an integer array A.

// Second argument is an integer B.



// Output Format

// Return 1 if there exist a subset with sum B else return 0.



// Example Input

// Input 1:

//  A = [3, 34, -3, 12, 5, 2]
//  B = 9
// Input 2:

//  A = [-8, 34, 4, 0, -5, -2]
//  B = -20


// Example Output

// Output 1:

//  1
// Output 2:

//  0


// Example Explanation

// Explanation 1:

//  There is a subset (-3, 12) with sum 9.
// Explanation 2:

//  There is no subset that add up to -20.

void checksubsetsum(int idx, vector<int>& A, int totalsum, vector<int>& subset, bool& flag) {
    if (flag) return;

    if (totalsum == 0) {
        flag = true;
        return;
    }

    if (idx == A.size()) {
        return;
    }

    checksubsetsum(idx + 1, A, totalsum, subset, flag);

    subset.push_back(A[idx]);

    checksubsetsum(idx + 1, A, totalsum - A[idx], subset, flag);

    subset.pop_back();
    
}

int Solution::SubsetSum(vector<int>& A, int B) {
    vector<int> subset;
    bool flag = false;
    
    checksubsetsum(0, A, B, subset, flag);

    return flag ? 1 : 0;
}
