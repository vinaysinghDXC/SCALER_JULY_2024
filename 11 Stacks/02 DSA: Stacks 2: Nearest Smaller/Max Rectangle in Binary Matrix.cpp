// https://www.scaler.com/academy/mentee-dashboard/class/236120/homework/problems/6?navref=cl_tt_lst_nm

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

int largestRectangleInHistogram(vector<int> &heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && currentHeight < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    return maxArea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    if (A.empty()) return 0;
    int N = A.size();
    int M = A[0].size();
    
    vector<int> heights(M, 0);
    int maxArea = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j] += 1;
            }
        }
        
        int area = largestRectangleInHistogram(heights);
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}
