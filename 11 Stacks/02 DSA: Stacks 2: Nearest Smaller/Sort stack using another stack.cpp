// https://www.scaler.com/academy/mentee-dashboard/class/236120/homework/problems/4347?navref=cl_tt_nv

// Problem Description

// Given a stack of integers A, sort it using another stack.

// Return the array of integers after sorting the stack using another stack.



// Problem Constraints

// 1 <= |A| <= 5000


// 0 <= A[i] <= 109




// Input Format

// The only argument is a stack given as an integer array A.



// Output Format

// Return the array of integers after sorting the stack using another stack.



// Example Input

// Input 1:

//  A = [5, 4, 3, 2, 1]
// Input 2:

//  A = [5, 17, 100, 11]


// Example Output

// Output 1:

//  [1, 2, 3, 4, 5]
// Output 2:

//  [5, 11, 17, 100]


// Example Explanation

// Explanation 1:

//  Just sort the given numbers.
// Explanation 2:

//  Just sort the given numbers.

vector<int> Solution::solve(vector<int> &A) {
    stack<int> inputStack;
    stack<int> tempStack;
    
    for (int i = 0; i < A.size(); i++) {
        inputStack.push(A[i]);
    }
    
    while (!inputStack.empty()) {
        int curr = inputStack.top(); // Get the top element
        inputStack.pop(); // Pop the top element
        
        while (!tempStack.empty() && tempStack.top() > curr) {
            inputStack.push(tempStack.top()); // Move elements from tempStack to inputStack
            tempStack.pop();
        }
        
        tempStack.push(curr); // Push the current element to its correct position
    }
    
    vector<int> sortedArray;
    while (!tempStack.empty()) {
        sortedArray.push_back(tempStack.top());
        tempStack.pop();
    }
    
    reverse(sortedArray.begin(), sortedArray.end());

    return sortedArray;    
}
