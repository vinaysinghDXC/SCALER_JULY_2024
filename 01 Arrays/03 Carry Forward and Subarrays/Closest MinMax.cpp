// Problem Description

// Given an array A, find the size of the smallest subarray such that it contains at least one occurrence of the maximum value of the array

// and at least one occurrence of the minimum value of the array.



// Problem Constraints

// 1 <= |A| <= 2000



// Input Format

// First and only argument is vector A



// Output Format

// Return the length of the smallest subarray which has at least one occurrence of minimum and maximum element of the array



// Example Input

// Input 1:

// A = [1, 3, 2]
// Input 2:

// A = [2, 6, 1, 6, 9]


// Example Output

// Output 1:

//  2
// Output 2:

//  3


// Example Explanation

// Explanation 1:

//  Take the 1st and 2nd elements as they are the minimum and maximum elements respectievly.
// Explanation 2:

//  Take the last 3 elements of the array.

//<CODE>
int Solution::solve(vector<int> &A) {
    int min=A[0];
    int max=A[0];
    for (int i=1; i<A.size(); i++){
        if(A[i]<min) min=A[i];
        if (A[i]>max) max=A[i];
    }

    int min_idx=-1;
    int max_idx=-1;
    int ans=A.size();

    for (int i=0; i<A.size(); i++){
        if (A[i]==min){
            min_idx=i;
        }
        if (A[i]==max){
            max_idx=i;
        }
        if (min_idx!=-1 && max_idx!=-1){
            if (abs(max_idx-min_idx)<ans) ans = abs(max_idx-min_idx)+1;
        }
    }
    return ans;
}
