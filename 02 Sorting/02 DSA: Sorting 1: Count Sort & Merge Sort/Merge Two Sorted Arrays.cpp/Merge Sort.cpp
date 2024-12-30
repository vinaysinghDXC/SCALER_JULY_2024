// https://www.scaler.com/academy/mentee-dashboard/class/236086/assignment/problems/21272?navref=cl_tt_nv

// Problem Description

// Given an integer array A, sort the array using Merge Sort.


// Problem Constraints

// 1 <= |A| <= 105
// 1 <= A[i] <= 109


// Input Format

// First argument is an integer array A.


// Output Format

// Return the sorted array.


// Example Input

// Input 1:-
// A = [1, 4, 10, 2, 1, 5]
// Input 2:-
// A = [3, 7, 1]


// Example Output

// Output 1:-
// [1, 1, 2, 4, 5, 10]
// Output 2:-
// [1, 3, 7]


// Example Explanation

// Explanation 1 and 2:
// Return the sorted array.

void merge2sorted(vector<int> &A, int s, int m, int e) {
    vector<int> arr(e - s + 1);
    int i = s, j = m + 1, k = 0;

    while (i <= m && j <= e) {
        if (A[i] < A[j]) {
            arr[k++] = A[i++];
        } else {
            arr[k++] = A[j++];
        }
    }

    while (i <= m) {
        arr[k++] = A[i++];
    }

    while (j <= e) {
        arr[k++] = A[j++];
    }

    for (int x = 0; x < arr.size(); x++) {
        A[s + x] = arr[x];
    }
}

void mergesort(vector<int> &A, int s, int e) {
    if (s >= e) return;  

    int m = (s + e) / 2;  

    // Recursively sort the first and second halves
    mergesort(A, s, m);
    mergesort(A, m + 1, e);

    // Merge the sorted halves
    merge2sorted(A, s, m, e);
}

vector<int> Solution::solve(vector<int> &A) {
    mergesort(A, 0, A.size() - 1);
    return A;
}