// https://www.scaler.com/academy/mentee-dashboard/class/236086/homework/problems/88770?navref=cl_tt_nv

// Problem Description

// You are given an array A of integers of length N and two indices, B and C.

// Your task is to sort the subarray [B, C] within the given array. The rest of the array should remain unchanged.



// Problem Constraints

// 1 ≤ N ≤ 105

// 0 ≤ A[i] ≤ 109

// 0 ≤ B ≤ C ≤ N - 1



// Input Format

// First argument is the array A of length N. The next two arguments are the integers B and C.



// Output Format

// Return the array after sorting the [B, C] subarray.



// Example Input

// Input:

// A = [59, 11, 8, 91, 49, 44, 8]
// B = 4
// C = 6
// Input 2:

// A = [50, 40, 30, 20, 10]
// B = 0
// C = 3


// Example Output

// Output:

// [59, 11, 8, 91, 8, 44, 49]
// Output:

// [20, 30, 40, 50, 10]


// Example Explanation

// Explanation 1:

// Initially the subarray [B, C], i.e. A[4, 6] = [49, 44, 8].
// After sorting this becomes [8, 44, 49].
// It can be seen that this subarray gets sorted and rest of the array remains unchanged!
// Explanation 2:

// Initially the subarray [B, C], i.e. A[0, 3] = [50, 40, 30, 20].
// After sorting this becomes [20, 30, 40, 50].
// It can be seen that this subarray gets sorted and rest of the array remains unchanged!

void merge(vector<int>& A, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    vector<int> left(leftSize);
    vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++)
        left[i] = A[start + i];
    for (int i = 0; i < rightSize; i++)
        right[i] = A[mid + 1 + i];

    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        A[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        A[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& A, int start, int end) {
    if (start == end) return;

    int mid = start + (end - start) / 2;

    mergeSort(A, start, mid);
    mergeSort(A, mid + 1, end);
    merge(A, start, mid, end);
}

vector<int> Solution::sortSubarray(vector<int> &A, int B, int C) {
    mergeSort(A, B, C);
    return A;
}
