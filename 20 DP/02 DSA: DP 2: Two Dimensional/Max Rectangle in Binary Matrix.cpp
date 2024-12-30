// https://www.scaler.com/academy/mentee-dashboard/class/297877/homework/problems/6?navref=cl_tt_lst_sl

// Problem Description

// Given a 2-D binary matrix A of size N x M filled with 0's and 1's, find the largest rectangle containing only ones and return its area.




// Problem Constraints

// 1 <= N, M <= 100



// Input Format

// The first argument is a 2-D binary array A.



// Output Format

// Return an integer denoting the area of the largest rectangle containing only ones.



// Example Input

// Input 1:

//  A = [
//        [1, 1, 1]
//        [0, 1, 1]
//        [1, 0, 0] 
//      ]
// Input 2:

//  A = [
//        [0, 1, 0]
//        [1, 1, 1]
//      ] 


// Example Output

// Output 1:

//  4
// Output 2:

//  3


// Example Explanation

// Explanation 1:


//  As the max area rectangle is created by the 2x2 rectangle created by (0, 1), (0, 2), (1, 1) and (1, 2).
// Explanation 2:

//  As the max area rectangle is created by the 1x3 rectangle created by (1, 0), (1, 1) and (1, 2).

 

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();
    int max_area = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] == 1 && i > 0) {
                A[i][j] += A[i - 1][j];
            }
        }
    }

    auto largestRectangleArea = [](vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!s.empty() && h < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                max_area = max(max_area, height * width);
            }
            s.push(i);
        }
        return max_area;
    };

    for (int i = 0; i < rows; i++) {
        vector<int> heights = A[i];
        max_area = max(max_area, largestRectangleArea(heights));
    }

    return max_area;
}
