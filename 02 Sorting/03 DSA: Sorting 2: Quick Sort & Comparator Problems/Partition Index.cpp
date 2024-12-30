// https://www.scaler.com/academy/mentee-dashboard/class/236098/assignment/problems/88621?navref=cl_tt_nv

// Problem Description

// Given an integer array A of length N, considering the last element as pivot p, rearrange the elements such that for all i:

// if A[i] < p then it should be present on left side of the partition
// if A[i] > p then it should be present on right side of the partition
// Rearrange the given array as well as return the partition index.

// Note: All elements are distinct



// Problem Constraints

// 1 ≤ N ≤ 105

// 1 ≤ A[i] ≤ 109



// Input Format

// The only input argument is the given vector A.



// Output Format

// Return the partition index as well as rearrange the input array to satisfy the given conditions.



// Example Input

// Input:

// A = [6, 2, 0, 4, 5]


// Example Output

// Output:

//  Valid
// A possible solution can be:
// A = [2, 0, 4, 5, 6] and partitionIndex = 3


// Example Explanation

// Explanation:

//  The rearrangement is valid because every element in [0, 2] index range is less than the pivot element, and every element in [3, 4] index range is greater than the pivot element.

int partition(vector<int> &arr) {
    // code here
    int n=arr.size();
    int p=arr[n-1];
    int l=0, r=n-2;
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
    swap(arr[l], arr[n-1]);
    return l;
}
