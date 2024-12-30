// https://www.scaler.com/academy/mentee-dashboard/class/236098/homework/problems/88620?navref=cl_tt_nv

// Problem Description

// Given an array A of 0s and 1s of length N. Sort this array.

// Note - Do not use any sorting algorithm or library's sort method.



// Problem Constraints

// 1 ≤ N ≤ 105

// 0 ≤ A[i] ≤ 1



// Input Format

// First argument A is an array of length N.



// Output Format

// Return the sorted array.



// Example Input

// Input 1:

// A = [0,0,1,0,1,1,0]
// Input 2:

// A = [1,0]


// Example Output

// Output 1:

// [0,0,0,0,1,1,1]
// Output 2:

// [0,1]

// Partition function for quicksort
int partition(vector<int> &A, int low, int high) {
    int pivot = A[high];  
    int i = low - 1;      

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;  
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]); 
    return (i + 1);
}

void quickSort(vector<int> &A, int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);  
        quickSort(A, low, pi - 1);         
        quickSort(A, pi + 1, high);        
    }
}

vector<int> Solution::sort01(vector<int> &A) {
    int n =A.size();
    quickSort(A, 0, n - 1);
    return A;
}
