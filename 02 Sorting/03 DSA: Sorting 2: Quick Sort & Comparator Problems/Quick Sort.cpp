// https://www.scaler.com/academy/mentee-dashboard/class/236098/assignment/problems/66911?navref=cl_tt_nv

// Problem Description

// Given an integer array A, sort the array using Quick Sort.


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

int partition(vector<int> &arr, int s, int e){
    int n=arr.size();
    int p=arr[s];
    int l=s+1, r=e;
    while(l<=r){
        if(arr[l]<p) l++;
        else if(arr[r]>p) r--;
        else{
            int temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;
            r--;
        }
    }
    swap(arr[s], arr[r]);
    return r;
}

void quicksort(vector<int> &A, int s, int e){
    if(s>=e) return;
    int pi=partition(A, s, e);
    quicksort(A, s, pi-1);
    quicksort(A, pi+1, e);
}

vector<int> Solution::solve(vector<int> &A) {
    quicksort(A, 0, A.size()-1);
    return A;
}
