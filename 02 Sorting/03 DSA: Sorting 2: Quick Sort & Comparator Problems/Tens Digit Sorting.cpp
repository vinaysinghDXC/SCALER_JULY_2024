// https://www.scaler.com/academy/mentee-dashboard/class/236098/homework/problems/32021?navref=cl_tt_nv

// Problem Description

// Given an array A of N integers. Sort the array in increasing order of the value at the tens place digit of every number.

// If a number has no tens digit, we can assume value to be 0.
// If 2 numbers have same tens digit, in that case number with max value will come first
// Solution should be based on comparator.


// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i] <= 109



// Input Format

// First argument A is an array of integers.



// Output Format

// Return the array after sorting



// Example Input

// Input 1:
// A = [15, 11, 7, 19]
// Input 2:
// A = [2, 24, 22, 19]


// Example Output

// Output 1:
// [7, 19, 15, 11]
// Output 2:
// [2, 19, 24, 22]


// Example Explanation

// For Input 1:
// The sorted order is [7, 19, 15, 11]. The tens digit of 7 is 0, 
// and that of 19, 15 and 11 is 1.
// For Input 2:
// The sorted order is [2, 19, 24, 22]. The tens digit of 2 is 0, 
// that of 19 is 1 and that of 22 and 24 is 2.

int getTensDigit(int num) {
    return abs(num / 10) % 10;
}

void merge(vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        int tensL = getTensDigit(L[i]);
        int tensR = getTensDigit(R[j]);

        // Custom comparator: compare tens digits first, then original values
        if (tensL < tensR) {
            A[k] = L[i];
            i++;
        } else if (tensL > tensR) {
            A[k] = R[j];
            j++;
        } else {
            // If tens digits are the same, put the larger number first
            if (L[i] > R[j]) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        merge(A, left, mid, right);
    }
}

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    mergeSort(A, 0, n - 1);
    return A;
}
