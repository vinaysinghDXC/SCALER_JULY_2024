// https://www.scaler.com/academy/mentee-dashboard/class/236114/homework/problems/5153?navref=cl_tt_lst_nm

// Problem Description

// Given an array of integers A of size N and an integer B.

// In a single operation, any one element of the array can be increased by 1. You are allowed to do at most B such operations.

// Find the number with the maximum number of occurrences and return an array C of size 2, where C[0] is the number of occurrences, and C[1] is the number with maximum occurrence.
// If there are several such numbers, your task is to find the minimum one.



// Problem Constraints

// 1 <= N <= 105

// -109 <= A[i] <= 109

// 0 <= B <= 109



// Input Format

// The first argument given is the integer array A.
// The second argument given is the integer B.



// Output Format

// Return an array C of size 2, where C[0] is number of occurence and C[1] is the number with maximum occurence.



// Example Input

// Input 1:

//  A = [3, 1, 2, 2, 1]
//  B = 3
// Input 2:

//  A = [5, 5, 5]
//  B = 3


// Example Output

// Output 1:

//  [4, 2]
// Output 2:

//  [3, 5]


// Example Explanation

// Explanation 1:

//  Apply operations on A[2] and A[4]
//  A = [3, 2, 2, 2, 2]
//  Maximum occurence =  4
//  Minimum value of element with maximum occurence = 2
// Explanation 2:

//  A = [5, 5, 5]
//  Maximum occurence =  3
//  Minimum value of element with maximum occurence = 5

bool canAchieve(const vector<long long>& prefixSum, const vector<int>& A, int B, int index, int count) {
    long long totalSumRequired = (long long)A[index] * count;
    long long currentSum = prefixSum[index] - (index - count >= 0 ? prefixSum[index - count] : 0);
    return totalSumRequired - currentSum <= B;
}


vector<int> Solution::solve(vector<int> &A, int B) {
   int N=A.size();
   sort(A.begin(), A.end());
    
    vector<long long> prefixSum(N);
    prefixSum[0] = A[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    int maxFreq = 1;
    int numberWithMaxFreq = A[0];
    
    for (int i = 0; i < N; i++) {
        int low = 1, high = i + 1, best = 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAchieve(prefixSum, A, B, i, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // Update the result if we find a larger frequency or a smaller number with the same frequency
        if (best > maxFreq) {
            maxFreq = best;
            numberWithMaxFreq = A[i];
        }
    }
    
    return {maxFreq, numberWithMaxFreq};   
}
