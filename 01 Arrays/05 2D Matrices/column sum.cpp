// Q1. Column Sum
// Solved
// feature icon
// Using hints except Complete Solution is Penalty free now
// Use Hint
// Problem Description

// You are given a 2D integer matrix A, return a 1D integer array containing column-wise sums of original matrix.



// Problem Constraints

// 1 <= A.size() <= 103

// 1 <= A[i].size() <= 103

// 1 <= A[i][j] <= 103



// Input Format

// First argument is a 2D array of integers.(2D matrix).



// Output Format

// Return an array containing column-wise sums of original matrix.



// Example Input

// Input 1:

// [1,2,3,4]
// [5,6,7,8]
// [9,2,3,4]


// Example Output

// Output 1:

// {15,10,13,16}


// Example Explanation

// Explanation 1

// Column 1 = 1+5+9 = 15
// Column 2 = 2+6+2 = 10
// Column 3 = 3+7+3 = 13
// Column 4 = 4+8+4 = 16

vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    if (A.size()==1 && A[0].size()==1) {
        ans.push_back(A[0][0]);
        return ans;
        }

    // cout<<"column length "<<A[0].size()<<endl;
    // cout<<"row length "<<A.size()<<endl;

    for (int j=0; j<A[0].size(); j++){
        int sum=0;
        for (int i=0; i<A.size(); i++){
            sum+=A[i][j];
        }
        ans.push_back(sum);
    }
    return ans;
}
