// https://www.scaler.com/academy/mentee-dashboard/class/297841/assignment/problems/90663?navref=cl_tt_nv_dd

// Problem Description

// Given an array A of N integers, convert that array into a min heap and return the array.

// NOTE: A min heap is a binary tree where every node has a value less than or equal to its children.



// Problem Constraints

// 1 ≤ N ≤ 10^5

// 0 ≤ A[i] ≤ 10^9



// Input Format

// First and only argument of input contains a single integer array A of length N.



// Output Format

// Return the reordered array A such that it forms a min heap.



// Example Input

// Input:

// A = [5, 13, -2, 11, 27, 31, 0, 19]


// Example Output

// Output:

// A = [-2, 5, 0, 13, 11, 19, 27, 31]


// Example Explanation

// One possible Heap is
  
//                 -2
//                /    \
//              5       0
//             / \    /  \
//           13  11  19   27
//           /
//         31

// It can be seen that each parent has a value smaller than its children. Hence it is a Valid Heap.

// The Heap in the Array format is [-2, 5, 0, 13, 11, 19, 27, 31].

// Some more possible heaps are  [-2, 0, 5, 13, 11, 27, 19, 31], [-2, 5, 0, 11, 27, 13, 19, 31], etc. 
// You can return any possible Valid Heap Structure.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
   public:
    void heapify(vector<int> &A, int i){
        while(i<A.size()){
            int min_i=i;
            int lci=2*i+1; // left child index
            if (lci<A.size() && A[lci]<A[min_i]) min_i=lci;
            int rci=2*i+2; // right child index
            if (rci<A.size() && A[rci]<A[min_i]) min_i=rci;
            if (i==min_i) break;
            else{
                swap(A[i], A[min_i]);
                i=min_i;
            }   
        }
    }
    vector<int> buildHeap(vector<int> &A) {
        for (int i = (A.size()-2)/2 ; i>=0; i--){   // A.size()-2 / 2 is becuase the leaf node are from A.size() - 2 / 2  +  1 to A.size(). So loop from A.size() - 2 / 2 to 0. A.size()-2 / 2 is => (N/2) -1
            heapify(A, i);
        }
        return A;
    }
};