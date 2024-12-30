// Problem Description

// You are given an array A. Print the elements of the array using recursion.

// NOTE :
// You are required to not use any loops, You can create new functions.
// Don't change the signature of the function PrintArray.
// Print a new empty line after printing the output.


// Problem Constraints

// 1 <= | A | <= 100
// -1000 <= A[i] <= 1000


// Input Format

// One line containing the array A


// Output Format

// Print the elements of the array in the sequential order.


// Example Input

// Input 1 :
// A = [6, -2, 5, 3]
// Input 2 :
// A = [1]


// Example Output

// Output 1 :
// 6 -2 5 3 
// Output 2 :
// 1 


// Example Explanation

// Print the elements in their order.

// https://www.scaler.com/academy/mentee-dashboard/class/236076/assignment/problems/122782?navref=cl_tt_nv

void printarr(vector<int> &A, int idx){
    if(idx==A.size()) return;
    cout<<A[idx]<<" ";
    printarr(A, idx+1);
}

void Solution::PrintArray(vector<int> &A) {
    printarr(A, 0);
    cout<<endl;
}
