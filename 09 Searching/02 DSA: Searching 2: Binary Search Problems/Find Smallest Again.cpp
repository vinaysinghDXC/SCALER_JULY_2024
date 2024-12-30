// https://www.scaler.com/academy/mentee-dashboard/class/236114/homework/problems/9155?navref=cl_tt_nv

// Problem Description

// Given an integer array A of size N.

// If we store the sum of each triplet of the array A in a new list, then find the Bth smallest element among the list.

// NOTE: A triplet consists of three elements from the array. Let's say if A[i], A[j], A[k] are the elements of the triplet then i < j < k.



// Problem Constraints

// 3 <= N <= 500
// 1 <= A[i] <= 108
// 1 <= B <= (N*(N-1)*(N-2))/6



// Input Format

// The first argument is an integer array A.
// The second argument is an integer B.



// Output Format

// Return an integer denoting the Bth element of the list.



// Example Input

// Input 1:

//  A = [2, 4, 3, 2]
//  B = 3
// Input 2:

//  A = [1, 5, 7, 3, 2]
//  B = 9


// Example Output

// Output 1:

//  9 
// Output 2:

//  14


// Example Explanation

// Explanation 1:

//  All the triplets of the array A are:

//  (2, 4, 3) = 9
//  (2, 4, 2) = 8
//  (2, 3, 2) = 7
//  (4, 3, 2) = 9

//  So the 3rd smallest element is 9.

int countTripletsLessThanOrEqualToMid(vector<int>& A, int mid) {
    int count = 0;
    int N = A.size();
    
    // Iterate over all possible i, j pairs and find the corresponding triplest
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                int sum = A[i] + A[j];
                int k = j + 1;
                while (k < N && sum + A[k] <= mid) {    // find the largest k such that A[i] + A[j] + A[k] <= mid
                    k++;
                }
                count += (k - (j + 1)); // The number of valid triplest
            }
        }
    return count;
}

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int N = A.size();
    
    int low = A[0] + A[1] + A[2];
    int high = A[N-1] + A[N-2] + A[N-3];
    int result = low;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = countTripletsLessThanOrEqualToMid(A, mid);
        
        if (count >= B) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}
