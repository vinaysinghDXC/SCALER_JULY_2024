// https://www.scaler.com/academy/mentee-dashboard/class/297841/assignment/problems/94303?navref=cl_tt_nv_dd

// Problem Description

// You have an empty min heap. You are given an array A consisting of N queries. Let P denote A[i][0] and Q denote A[i][1]. There are two types of queries:

// P = 1, Q = -1 : Pop the minimum element from the heap.
// P = 2, 1 <= Q <= 109 : Insert Q into the heap.

// Return an integer array containing the answer for all the extract min operation. If the size of heap is 0, then extract min should return -1.



// Problem Constraints

// 1 <= N <= 105

// 1 <= A[i][0] <= 2

// 1 <= A[i][1] <= 109 or A[i][1] = -1



// Input Format

// The only argument A is a 2D integer array



// Output Format

// Return an integer array



// Example Input

// Input 1:

// A = [[1, -1], [2, 2], [2, 1], [1, -1]]
// Input 2:

// A = [[2, 5], [2, 3], [2, 1], [1, -1], [1, -1]]


// Example Output

// Output 1:

// [-1, 1]
// Output 2:

// [1, 3]


// Example Explanation

// Explanation 1:

// For the first extract operation the heap is empty so it gives -1. For the second extract operation the heap contains the elements 2 and 1. Extract min returns the element 1.
// Explanation 2:

// The heap contains the elements 5, 3 and 1. The first extract min operation gets the element 1 and the second operation gets the element 3.


void heapify(vector<int> &A, int i) {
    int n = A.size();
    while (i < n) {
        int min_i = i;
        int lci = 2 * i + 1;
        int rci = 2 * i + 2;
        
        if (lci < n && A[lci] < A[min_i]) min_i = lci;
        if (rci < n && A[rci] < A[min_i]) min_i = rci;
        
        if (i == min_i) break;
        else {
            swap(A[i], A[min_i]);
            i = min_i;
        }
    }
}

void insert(vector<int> &minheap, int x) {
    minheap.push_back(x);
    int i = minheap.size() - 1;
    while (i > 0) {
        int pi = (i - 1) / 2;
        if (minheap[pi] > minheap[i]) {
            swap(minheap[pi], minheap[i]);
            i = pi;
        } else {
            break;
        }
    }
}

int extractMin(vector<int> &minheap) {
    if (minheap.empty()) {
        return -1;
    }
    int minVal = minheap[0];
    minheap[0] = minheap.back();
    minheap.pop_back();
    if (!minheap.empty()) {
        heapify(minheap, 0);
    }
    return minVal;
}

vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> result;
    vector<int> minheap;

    for (auto& query : A) {
        int P = query[0];
        int Q = query[1];

        if (P == 1 && Q == -1) {
            if (minheap.empty()) {
                result.push_back(-1);
            } else {
                int nres = extractMin(minheap);
                result.push_back(nres);
            }
        } 
        else if (P == 2) {
            insert(minheap, Q);
        }
    }

    return result;
}
