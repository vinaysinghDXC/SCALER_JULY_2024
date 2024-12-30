// https://www.scaler.com/academy/mentee-dashboard/class/236098/homework/problems/167?navref=cl_tt_nv

// Problem Description

// Given an array with N objects colored red, white, or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will represent the colors as,

// red -> 0
// white -> 1
// blue -> 2

// Note: Using the library sort function is not allowed.



// Problem Constraints

// 1 <= N <= 1000000
// 0 <= A[i] <= 2


// Input Format

// First and only argument of input contains an integer array A.


// Output Format

// Return an integer array in asked order


// Example Input

// Input 1 :
//     A = [0, 1, 2, 0, 1, 2]
// Input 2:

//     A = [0]


// Example Output

// Output 1:
//     [0, 0, 1, 1, 2, 2]
// Output 2:

//     [0]


// Example Explanation

// Explanation 1:
//     [0, 0, 1, 1, 2, 2] is the required order.
// Explanation 2:
//     [0] is the required order
void merge(vector<int> &A, int s, int e){
    int m = s+(e-s)/2;

    int n1=m-s+1;
    int n2=e-m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i =0; i<n1; i++){
        L[i]=A[s+i];
    }

    for (int i =0; i<n2; i++){
        R[i]=A[m+1+i];
    }

    int i =0, j=0, k=s;

    while(i<n1 && j<n2){
        if (L[i]<R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
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

void mergeSort(vector<int> &A, int s, int e){
    if (s>=e) return;

    int m = s+(e-s)/2;

    mergeSort(A, s, m);
    mergeSort(A, m+1, e);

    merge(A, s, e);
}

vector<int> Solution::sortColors(vector<int> &A) {
    int n = A.size();

    mergeSort(A, 0, n - 1);

    return A; 

}

