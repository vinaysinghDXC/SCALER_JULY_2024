// Problem Description

// Given a 2D integer array A, return the transpose of A.

// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.


// Problem Constraints

// 1 <= A.size() <= 1000






// 1 <= A[i].size() <= 1000

// 1 <= A[i][j] <= 1000






// Input Format

// First argument is a 2D matrix of integers.





// Output Format

// You have to return the Transpose of this 2D matrix.



// Example Input

// Input 1:




// A = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]
// Input 2:

// A = [[1, 2],[1, 2],[1, 2]]





// Example Output

// Output 1:






// [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
// Output 2:









// [[1, 1, 1], [2, 2, 2]]





// Example Explanation

// Explanation 1:

// Clearly after converting rows to column and columns to rows of [[1, 2, 3],[4, 5, 6],[7, 8, 9]]
//  we will get [[1, 4, 7], [2, 5, 8], [3, 6, 9]].
// Explanation 2:

// After transposing the matrix, A becomes [[1, 1, 1], [2, 2, 2]]

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    
    if (A.size()==A[0].size()){
        for (int i =0; i<A.size()-1; i++){
            for (int j=i+1; j<A.size(); j++){
                int temp=A[i][j];
                A[i][j]=A[j][i];
                A[j][i]=temp;
            }
        }
        return A;
    }
    vector<vector<int> > ans(A[0].size(), vector<int>(A.size()));
    for (int j=0; j<A[0].size(); j++){
        for (int i=0; i<A.size(); i++){
            ans[j][i]=A[i][j];
        }
    }
    return ans;
}
